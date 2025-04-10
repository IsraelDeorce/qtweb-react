import { useNavigate } from "react-router-dom"

function About() {
  const navigate = useNavigate()

  return (
    <>
      <h2>About Page</h2>
      <button onClick={() => navigate('/')}>Go to Home</button>
      <button onClick={() => navigate('/about')}>Go to Info</button>
    </>
  )
}

export default About
