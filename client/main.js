
const b = document.getElementById('doStuffButton');
b.onclick = () => fetch(window.location.origin + '/doStuff');

let imgLoaded = false;
const img = document.createElement('img');
img.src = window.location.origin + '/img';
img.onload = () => { imgLoaded = true; };
document.body.appendChild(img);

setInterval(() => {
    if (imgLoaded) {
        imgLoaded = false;
        // workaround for no cache
        img.src = window.location.origin + '/img?date=' + new Date().getTime();
    }
}, 500);
