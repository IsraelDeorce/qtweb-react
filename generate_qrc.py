import os

dist_dir = "ui/dist"
qrc_file = "resources.qrc"

with open(qrc_file, "w", encoding="utf-8") as f:
    f.write('<RCC>\n  <qresource prefix="/">\n')

    for root, _, files in os.walk(dist_dir):
        for filename in files:
            file_path = os.path.join(root, filename)
            alias = os.path.relpath(file_path, dist_dir).replace("\\", "/")
            source = file_path.replace("\\", "/")
            f.write(f'    <file alias="{alias}">{source}</file>\n')

    f.write("  </qresource>\n</RCC>\n")

print(f"✅ {qrc_file} generated with all files from {dist_dir}")
