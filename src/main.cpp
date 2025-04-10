#include <QApplication>
#include <QWebEngineView>
#include <QUrl>
#include <QDir>
#include <QObject>
#include <QWebChannel>
#include <QDebug>
#include <QJsonObject>

class MyBackend : public QObject {
    Q_OBJECT

    public:
        MyBackend(QObject *parent = nullptr) : QObject(parent) {}

    public slots:

        Q_INVOKABLE QJsonObject authenticate(const QJsonObject& data) {
            qDebug() << "Received data from React: " << data;
            
            try {
                doAuthentication(data["username"].toString(), data["password"].toString());
            }
            catch (const std::exception& e) {
                return QJsonObject({
                    {"status", "error"},
                    {"message", e.what()}
                });
            }
            
            return QJsonObject({
                {"status", "success"},
                {"message", "Authenticated successfully!"}
            });
        }

    private:

        void doAuthentication(const QString& username, const QString& password) {
            qDebug() << "Authenticating user: " << username << " with password: " << password;
            if (username == "admin" && password == "admin") {
                qDebug() << "Authentication successful!";
            } else {
                throw std::runtime_error("Invalid username or password");
            }
        }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFileInfo jsFileInfo(QDir::currentPath() + "/../ui/dist/qwebchannel.js");

    if (!jsFileInfo.exists()) {
        QFile::copy(":/qtwebchannel/qwebchannel.js",jsFileInfo.absoluteFilePath());
        qDebug() << "Copied qwebchannel.js to " << jsFileInfo.absoluteFilePath();
    }

    QWebEngineView view;
    QDir appDir(QApplication::applicationDirPath());

    // view.setUrl(QUrl("http://localhost:5173/")); // works if server is running ($ npm run dev)
    view.setUrl(QUrl("qrc:/index.html"));
    
    // Expose C++ object to JavaScript
    MyBackend backend;
    QWebChannel channel;
    channel.registerObject("backend", &backend);
    view.page()->setWebChannel(&channel);

    view.showMaximized();
    
    qDebug() << "Opening devTools";
    QWebEngineView devToolsView;
    devToolsView.page()->setInspectedPage(view.page());
    devToolsView.show();
    

    return app.exec();
}

//#include "main.moc" // Include the generated moc file
#include "main.moc"