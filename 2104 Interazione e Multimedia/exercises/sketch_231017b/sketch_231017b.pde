size(1000, 800);
background(125);

for (int i = 10; i >= 0; i--) {
  fill(i%2 == 0 ? 255 : 0);
  ellipse(130, 130, 25*i, 25*i);
}
fill(255, 255, 0, 128);
ellipse(130, 130, 250, 250);

ellipseMode(CORNER);
fill(0,0,255);
stroke(0, 255, 0);
point(400, 130);
noStroke();
ellipse(400, 130, 50, 50);

ellipseMode(RADIUS);

int x = 0;
while (x < width) {
  for (int i = 0; i < 255; i++) {
    stroke(255-i, i, 0);
    line(x, 260, x, 360);
    x++;
  }
  for (int i = 0; i < 255; i++) {
    stroke(0, 255-i, i);
    line(x, 260, x, 360);
    x++;
  }
  for (int i = 0; i < 255; i++) {
    stroke(i, 0, 255-i);
    line(x, 260, x, 360);
    x++;
  }
}

noStroke();
fill(255);
rect(20, 380, 200, 100);
