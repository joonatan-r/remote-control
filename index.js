
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
app.get('/mousePos', (req, res) => {
    exec('mousepos', (err, stdout, stderr) => {
        const coords = stdout.split(' ').map(i => Number(i));
        if (coords.length === 2) {
            res.send(JSON.stringify(coords));
        }
    });
});
app.get('/mouseMove', (req, res) => {
    exec('mousemove ' + req.query.arg1 + ' ' + req.query.arg2);
    res.sendStatus(200);
});
app.get('/mousePress', (req, res) => {
    exec('mousepress ' + req.query.arg1 + ' ' + req.query.arg2);
    res.sendStatus(200);
});
app.get('/press', (req, res) => {
    exec('press ' + req.query.arg1 + ' ' + req.query.arg2);
    res.sendStatus(200);
});
