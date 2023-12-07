
let imgLoaded = false;
let naturalHeight = 0;
let naturalWidth = 0;
const img = document.createElement('img');
img.src = window.location.origin + '/img';
img.onload = () => {
    imgLoaded = true;
    if (naturalHeight === 0 || naturalWidth === 0) {
        // store only once as seem to be able to be 0 if not fully loaded 
        naturalHeight = img.naturalHeight;
        naturalWidth = img.naturalWidth;
    }
};
img.onmousedown = (e) => {
    const rect = e.target.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;
    const relativeX = x / rect.width;
    const relativeY = y / rect.height;
    const pixelX = relativeX * naturalWidth;
    const pixelY = relativeY * naturalHeight;
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
mouse.innerHTML = 'V';
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

const pressed = {};
const selection = document.getElementById('selection');
const pressButton = document.getElementById('pressButton');
pressButton.onclick = () => {
    const currentVal = selection.options[selection.selectedIndex].value;
    const action = pressed[currentVal] ? 'u' : 'd';

    if (currentVal === 'mouseLeft') {
        fetch(window.location.origin + '/mousePress?arg1=l&arg2=' + action);
    } else if (currentVal === 'mouseRight') {
        fetch(window.location.origin + '/mousePress?arg1=r&arg2=' + action);
    } else {
        fetch(window.location.origin + '/press?arg1=' + currentVal + '&arg2=' + action);
    }
    pressed[currentVal] = !pressed[currentVal];
    pressButton.innerHTML = pressed[currentVal] ? 'Up' : 'Down';
};
selection.onchange = () => {
    const currentVal = selection.options[selection.selectedIndex].value;
    pressButton.innerHTML = pressed[currentVal] ? 'Up' : 'Down';
};
