
let imgLoaded = false;
const img = document.createElement('img');
img.src = window.location.origin + '/img';
img.onload = () => { imgLoaded = true; };
img.onclick = (e) => {
    const rect = e.target.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;
    const relativeX = x / rect.width;
    const relativeY = y / rect.height;
    const pixelX = relativeX * img.naturalWidth;
    const pixelY = relativeY * img.naturalHeight;
    fetch(window.location.origin + '/mouseMove?arg1=' + pixelX + '&arg2=' + pixelY);
}
document.body.appendChild(img);
const mouse = document.createElement('p');
mouse.style.color = 'red';
mouse.style.position = 'absolute';
mouse.style.top = -50;
mouse.style.left = -50;
mouse.style.margin = '0px';
mouse.style.padding = '0px';
mouse.innerHTML = '^';
document.body.appendChild(mouse);

async function updateMouse() {
    fetch(window.location.origin + '/mousePos')
        .then(r => r.json())
        .then(r => {
            mouse.style.left = r[0] + 'px';
            mouse.style.top = r[1] + 'px';
        });
}

updateMouse();

setInterval(() => {
    if (imgLoaded) {
        imgLoaded = false;
        // workaround for no cache
        img.src = window.location.origin + '/img?date=' + new Date().getTime();
        updateMouse();
    }
}, 500);
