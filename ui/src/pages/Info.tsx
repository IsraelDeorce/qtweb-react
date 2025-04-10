import { useNavigate } from "react-router-dom"

function Info() {
  const navigate = useNavigate()

  return (
    <>
      <h2>Info Page</h2>
      <button onClick={() => navigate('/')}>Go to Home</button>
      <button onClick={() => navigate('/about')}>Go to About</button>
    </>
  )
}

export default Info
