
size(500, 500);
background(255);
//background(255, 10, 100);

line(0, 0, width, height);
stroke(200, 100, 255); // imposta il colore
point(10, 20);

ellipse(250, 250, 200, 50); // x, y, larghezza, altezza
noStroke();
ellipse(250, 250, 200, 50); // x, y, larghezza, altezza

noFill();

print(width);
println("Prova", width);


int radius = (int)(500*sqrt(2));
for (int i = 0; i < radius; i += 10) {
  int x = 255-255*i/radius;
  fill(x, x, x);
  noStroke();
  ellipse(250, 250, radius-i, radius-i);
}
 
