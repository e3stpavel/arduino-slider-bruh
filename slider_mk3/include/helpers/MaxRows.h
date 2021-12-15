void rows() {
  for(int row=0;row<8;row++) {
    delay(500);
    lc.setRow(0,row,B10100000);
    delay(500);
    lc.setRow(0,row,(byte)0);
    for(int i=0;i<row;i++) {
      delay(500);
      lc.setRow(0,row,B10100000);
      delay(500);
      lc.setRow(0,row,(byte)0);
    }
  }
}