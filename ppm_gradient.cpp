#include <fstream>
#include <cstring>

int digits_in_int(int x){
  int digits;
  for(digits = 1; x >= 10; digits++, x /= 10);
  return digits;
}

int calc_header_size(int width, int height, int maxvalue){
  return digits_in_int(width) + digits_in_int(height) + digits_in_int(maxvalue) + 6;
}

void itoa(char *str, int n){
  char *s;
  for(s = str; n > 0; str++, n /= 10){
    *str = (n % 10) + '0';
  }

  /* check for n == 0 */
  if(s == str){
    *str = '0';
    str++;
  }

  *str = 0;

  /* reverse the string */
  char *tmp;
  while(str > s){
    *tmp = *s;
    *s = *str;
    *str = *tmp;
    s++;
    str--;
  }
}

void make_header(char *image, const int width, const int height, const int maxvalue){
  char *wstr = new char[digits_in_int(width)];
  char *hstr = new char[digits_in_int(height)];
  char *mstr = new char[digits_in_int(maxvalue)];

  itoa(wstr, width);
  itoa(hstr, height);
  itoa(mstr, maxvalue);

  std::strcpy(image, "P6 ");
  std::strcat(image, wstr);
  std::strcat(image, " ");
  std::strcat(image, hstr);
  std::strcat(image, " ");
  std::strcat(image, mstr);
  std::strcat(image, " ");
  
  delete [] wstr;
  delete [] hstr;
  delete [] mstr;
}

void make_pixels(char *image, const int width, const int height, const int maxvalue){
  int x,y,r,g,b = maxvalue/ 2;
  for(y = 0; y < height; y++){
    g = y * maxvalue / height;
    for(x = 0; x < width; x++){
      r = x * maxvalue / width;
      *image = r;
      image++;
      *image = g;
      image++;
      *image = b;
      image++;
    }
  }
}

char *make_image(const int width, const int height, const int maxvalue, int *total_size){
  int header_size = calc_header_size(width, height, maxvalue);
  int image_size = width * height * 3;
  *total_size = header_size + image_size;
  char *image = new char[*total_size];

  make_header(image, width, height, maxvalue);
  make_pixels(image + header_size, width, height, maxvalue);

  return image;
}

void save_image(char *image, const int total_size){
  std::ofstream fout("gradient.ppm");
  fout.write(image, total_size);
  fout.close();
}

int main(){
  const int width = 512;
  const int height = 512;
  const int maxvalue = 255;
  int total_size;

  char *image = make_image(width, height, maxvalue, &total_size);

  save_image(image, total_size);

  delete [] image;
  return 0;
}
