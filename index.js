
const { exec } = require('node:child_process');
const screenshot = require('screenshot-desktop');
const path = require('path');
const express = require('express');

const app = express();
const port = 3000;
const server = app.listen(port, () => {
  console.log(`Example app listening on port ${port}`);
});
app.all('*', (req, res, next) => {
    console.log(req.ip);
    next();
});
app.use('/', express.static(path.join(__dirname, 'client')));
app.get('/doStuff', () => {
    exec('press b');
});
app.get('/img', (req, res) => {
    screenshot({ format: 'png', filename: './test.png' })
        .then((img) => {
            res.set('Cache-Control', 'max-age=0, must-revalidate');
            res.sendFile(path.join(__dirname, 'test.png'));
        })
        .catch((err) => {
            console.log(err);
        });
});

// exec('mousepos', (err, stdout, stderr) => {
//     const coords = stdout.split(' ').map(i => Number(i));
//     if (coords.length === 2) {
//         console.log('x ' + coords[0] + ', y ' + coords[1]);
//     }
// });
