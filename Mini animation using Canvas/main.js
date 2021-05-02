let c = document.getElementById("myCanvas");
let ctx = c.getContext("2d");

/* *************** */
// load single image as img
let ldimg = (src, callback) => {
  let img = document.createElement("img");
  img.onload = () => callback(img);
  img.src = src;
};
/* *************** */

/* *************** */
// source path of each animation image using a-animation string and fno-frame no
let imgpath = (fno, a) => {
  return "images/" + a + "/" + fno + ".png";
};
// frames obj-has no. of imgs in each ani
let frames = {
  forward: [1, 2, 3, 4, 5, 6],
  backward: [1, 2, 3, 4, 5, 6],
  kick: [1, 2, 3, 4, 5, 6, 7],
  punch: [1, 2, 3, 4, 5, 6, 7],
  block: [1, 2, 3, 4, 5, 6, 7, 8, 9],
  idle: [1, 2, 3, 4, 5, 6, 7, 8],
};
/* *************** */

/* *************** */
// loading all images before displaying in canvas
let ldallimgs = (callback) => {
  let images = {
    forward: [],
    backward: [],
    kick: [],
    punch: [],
    block: [],
    idle: [],
  };
  let ctr = 0;

  ["forward", "backward", "kick", "punch", "block", "idle"].forEach((a) => {
    let aframes = frames[a];
    ctr = ctr + aframes.length;

    aframes.forEach((fno) => {
      let path = imgpath(fno, a);

      ldimg(path, (img) => {
        images[a][fno - 1] = img; //loaded image
        ctr -= 1;
        if (ctr === 0) callback(images);
      });
    });
  });
};
/* *************** */

/* *************** */
// looping over imgs for animation effect
let animate = (ctx, images, a, callback) => {
  images[a].forEach((img, i) => {
    setTimeout(() => {
      ctx.clearRect(0, 0, 500, 500);
      ctx.drawImage(img, 0, 0, 320, 320);
    }, i * 100);
  });
  setTimeout(callback, images[a].length * 100);
};
/* *************** */

// calling functions
ldallimgs((images) => {
  let qa = [];

  let aux = () => {
    let sela = "";
    if (qa.length === 0) sela = "idle";
    else sela = qa.shift();
    animate(ctx, images, sela, aux);
  };
  aux();

  // button click event
  document.getElementById("forward").onclick = () => qa.push("forward");
  document.getElementById("backward").onclick = () => qa.push("backward");
  document.getElementById("kick").onclick = () => qa.push("kick");
  document.getElementById("punch").onclick = () => qa.push("punch");
  document.getElementById("block").onclick = () => qa.push("block");

  // keyboard click event
  document.addEventListener("keyup", (event) => {
    const key = event.key;
    switch (key) {
      case "ArrowUp":
        qa.push("forward");
        break;
      case "ArrowDown":
        qa.push("backward");
        break;
      case "ArrowLeft":
        qa.push("kick");
        break;
      case "ArrowRight":
        qa.push("punch");
        break;
      case " ":
        qa.push("block");
        break;
    }
  });
});
