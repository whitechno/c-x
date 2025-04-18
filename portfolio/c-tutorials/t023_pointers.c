#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *a, int *b) {
  printf("a: %p\nb: %p\n", a, b);
  int temp = *a;
  *a = *b;
  *b = temp;
}
void dyn_mem() {
  int *a;
  printf("a: %p\n", a);
  int length = 3;
  //    printf("Enter a length: ");
  //    scanf("%d", &length);
  a = malloc(length * sizeof(int));
  printf("a: %p\n", a);
  for (int i = 0; i < length; i++) a[i] = i * i;
  for (int i = 0; i < length; i++) printf("a[%d]=%d\n", i, a[i]);
  free(a);
  printf("a: %p\n", a);
  for (int i = 0; i < length; i++) printf("a[%d]=%d\n", i, a[i]);
}
void type_size() {
  printf("sizeof(_Bool): %zu\n", sizeof(_Bool));
  printf("sizeof(char): %zu\n", sizeof(char));
  printf("sizeof(char*): %zu\n", sizeof(char *));
  printf("sizeof(short): %zu\n", sizeof(short));
  printf("sizeof(int): %zu\n", sizeof(int));
  printf("sizeof(int*): %zu\n", sizeof(int *));
  printf("sizeof(long): %zu\n", sizeof(long));
  printf("sizeof(float): %zu\n", sizeof(float));
  printf("sizeof(double): %zu\n", sizeof(double));
  printf("sizeof(long double): %zu\n", sizeof(long double));
}
void struct_size() {
  struct BitFields {
    _Bool b1 : 1;
    _Bool b2 : 1;
    _Bool b3 : 1;
    _Bool b4 : 1;
    _Bool b5 : 1;
    _Bool b6 : 1;
    _Bool b7 : 1;
    _Bool b8 : 1;
  };
  printf("sizeof(BitFields): %zu\n", sizeof(struct BitFields));
  struct BitFields bf = {0, 0, 0, 0, 0, 0, 0, 0};
  printf("&bf: %p\n", &bf);
  struct SmallToLarge { // 16
    char c;
    char c2;
    int i;
    long l;
  };
  printf("sizeof(SmallToLarge): %zu\n", sizeof(struct SmallToLarge));
  struct Mixed { // 24
    char c;
    int i;
    long l;
    char c2;
  };
  printf("sizeof(Mixed): %zu\n", sizeof(struct Mixed));
  struct LargeToSmall { // 16
    long l;
    int i;
    char c;
    char c2;
  };
  printf("sizeof(LargeToSmall): %zu\n", sizeof(struct LargeToSmall));
  struct Book { // 32
    char title[10];
    double price;
    int pages;
  };
  printf("sizeof(Book): %zu\n", sizeof(struct Book));
  struct Book2 { // 24
    char title[10];
    int pages;
    double price;
  };
  printf("sizeof(Book2): %zu\n", sizeof(struct Book2));
}
void int_array_arg(int aa[]) {
  printf("sizeof(aa): %zu\n", sizeof(aa)); // 8, not 12
  // because aa is a pointer to the first element of the array
  // sizeof(aa) is the size of a pointer, not the size of the array
  printf("aa: %p\n", aa);
  aa[0] = -1;
}
void int_array() {
  int a[] = {1, 2, 3};
  printf("sizeof(a): %zu\n", sizeof(a)); // 12
  printf("a: %p\n", a);
  int *ptr = a;
  for (int i = 0; i < 3; i++) {
    printf("ptr: %p\n", ptr);
    printf("a[%d]: %d\n", i, *ptr);
    ptr++;
  }
  int_array_arg(a);
  printf("a[0]: %d\n", a[0]);
  // Remember:
  int *ptr2 = a + 2; // same as &a[2], ptr2 points to third element
  int value = *ptr2; // value is 3
  printf("value: %d\n", value);
  printf("ptr2: %p\n", ptr2);
  printf("ptr2[0]: %d\n", ptr2[0]); // same as *ptr2
  // going beyond the array
  ptr2++;
  printf("ptr2: %p\n", ptr2);
  printf("*ptr2: %d\n", *ptr2);
  // Taking the address of an array with &arr gives a pointer to the array
  // itself, not to the first element.
  // The type of &arr is int (*)[3], which is a pointer to an array of 3 ints.
  int (*ptr3)[3] = &a; // ptr3 points to the whole array
  printf("sizeof(*ptr3): %zu\n", sizeof(*ptr3)); // 12
  printf("ptr3: %p\n", ptr3);
  printf("(*ptr3)[0]: %d\n", (*ptr3)[0]); // same as a[0]
}
void struct_array() {
  char title[10];
  printf("sizeof(title): %zu\n", sizeof(title));
  struct Book {
    char title[10];
    double price;
    int pages;
  };
  printf("sizeof(Book): %zu\n", sizeof(struct Book));
  struct Book bs[3] = {{"Learn C", 650.50, 325},
                       {"C Pointers", 175, 225},
                       {"C Pearls", 250, 250}};
  printf("sizeof(struct Book bs[3]): %zu\n", sizeof(bs));
  printf("bs: %p\n", bs);
  struct Book *ptr = bs;
  for (int i = 0; i < 3; i++) {
    printf("ptr: %p\n", ptr);
    printf("Title: %s \tPrice: %7.2lf \tPages: %d\n", ptr->title, ptr->price,
           ptr->pages);
    ptr++;
  }
}
void concat_str(char *s1, const char *s2) {
  // Concatenate s2 to s1
  while (*s1) s1++;
  while (*s2) {
    *s1 = *s2;
    s1++;
    s2++;
  }
  *s1 = '\0';
}
void test_concat_str() {
  char s1[20] = "Hello";
  char s2[] = " World!";
  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);
  concat_str(s1, s2);
  printf("s1: %s\n", s1);

  strcpy(s1, "");
  strcpy(s2, "");
  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);
  concat_str(s1, s2);
  printf("s1: %s\n", s1);
}

int main() {
  int b = 42;
  // The `&` operator returns the memory address of a variable.
  int *a = &b;

  printf("b: %d\n", b);
  printf("&b: %p\n", &b);
  printf("a: %p\n", a);
  printf("*a: %d\n", *a);

  // The `*` operator dereferences a pointer.
  // Dereferencing a pointer allows us to access the value in the variable
  // at the memory address stored in the pointer.
  *a = 50;
  printf("b: %d\n", b);

  printf("\n Swap x and y.\n");
  int x, y;
  x = 5;
  y = 10;
  printf("&x: %p\n&y: %p\n", &x, &y);
  printf("x: %d, y: %d\n", x, y);
  swap(&x, &y);
  printf("x: %d, y: %d\n", x, y);

  printf("\n dyn_mem\n");
  dyn_mem();

  printf("\n type_size\n");
  type_size();

  printf("\n struct_size\n");
  struct_size();

  printf("\n int_array\n");
  int_array();

  printf("\n struct_array\n");
  struct_array();

  printf("\n test_concat_str\n");
  test_concat_str();

  return 0;
}
