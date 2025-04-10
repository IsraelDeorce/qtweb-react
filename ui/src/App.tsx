import { HashRouter as Router, Routes, Route, Link } from 'react-router-dom'
import Home from './pages/Home'
import About from './pages/About'
import Info from './pages/Info'
import './App.css'

function App() {
  console.log("Location: ", window.location)
  return (
    <Router>
      <nav style={{ marginBottom: '1rem' }}>
        <Link to="/">Home</Link> | <Link to="/about">About</Link> | <Link to="/info">Info</Link>
      </nav>

      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/about" element={<About />} />
        <Route path="/info" element={<Info />} />
      </Routes>
    </Router>
  )
}

export default App
