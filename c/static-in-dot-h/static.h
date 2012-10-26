static int static_data = 10;
static void init(int a){
  static_data += a;
}
