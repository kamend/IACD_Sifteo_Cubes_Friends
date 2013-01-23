
int pixelWidth = 18;
int pixelHeight = 18;

PrintWriter writer;
PImage img;

void setup() {
  size(500,500);
  
  img = loadImage("4friends.png");
  img.loadPixels();
  
  writer = createWriter("4friends.txt");
  
  // red color
  writer.println("nbColor = draw.RED;");
  for(int x=0;x<pixelWidth;x++) {
    for(int y =0;y<pixelHeight;y++) {
       int pindex = x + y * pixelWidth;
       color c = img.get(x,y);
       
       if(red(c) > 200.0 && blue(c) < 20.0 && green(c)< 20.0) {
           
         writer.println("draw.fill(vec("+x+","+y+"),vec(1,1),nbColor | draw.SOLID_FG);");
         
       }
        
    }
  
  }
  
    // white color
  writer.println("nbColor = draw.WHITE;");
  for(int x=0;x<pixelWidth;x++) {
    for(int y =0;y<pixelHeight;y++) {
       int pindex = x + y * pixelWidth;
       color c = img.get(x,y);
       
       if(red(c) > 200.0 && blue(c) > 200.0 && alpha(c) > 200.0) {
           
         writer.println("draw.fill(vec("+x+","+y+"),vec(1,1),nbColor | draw.SOLID_FG);");
         
       }
        
    }
  
  }
}

void keyPressed() {
  writer.flush();
  writer.close();
  exit();
}

void draw() {
  background(0);
  image(img, 0,0);

}
