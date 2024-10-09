// Import required modules
const express = require('express');

// Create an instance of Express
const app = express();
const port = 3000; // Define the port number

// Define a route for GET requests
app.get('/ping', (req, res) => {
  res.send('pong');
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
