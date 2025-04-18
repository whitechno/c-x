#include <stdio.h>

void print_binary(unsigned char c) {
  for (int i = 7; i >= 0; i--) { printf("%d", (c >> i) & 1); }
}

void print_ascii_table() {
  printf("DEC  HEX   BIN      CHR Description\n");
  printf("---  ----  -------- --- -----------\n");

  // Print ASCII characters (0 to 255)
  for (unsigned char i = 0; i <= 255; i++) {
    printf("%3d  0x%02X ", i, i);
    printf(" ");
    print_binary(i);
    printf("  %c  ", i);

    // Print description for some special characters
    if (i == '\0') printf("Null character");
    else if (i == 1) printf("Start of Heading");
    else if (i == 2) printf("Start of Text");
    else if (i == 3) printf("End of Text");
    else if (i == 4) printf("End of Transmission");
    else if (i == 5) printf("Enquiry");
    else if (i == 6) printf("Acknowledge");
    else if (i == 7) printf("Bell");
    else if (i == 8) printf("Backspace");
    else if (i == 9) printf("Horizontal Tab '\\t'");
    else if (i == 10) printf("Line Feed '\\n'");
    else if (i == 11) printf("Vertical Tab");
    else if (i == 12) printf("Form Feed");
    else if (i == 13) printf("Carriage Return");
    else if (i == 14) printf("Shift Out");
    else if (i == 15) printf("Shift In");
    else if (i >= 16 && i <= 31) printf("Control character");
    else if (i == 32) printf("Space");
    else if (i == 33) printf("Exclamation mark");
    else if (i == 34) printf("Double quote");
    else if (i == 35) printf("Hash");
    else if (i == 36) printf("Dollar");
    else if (i == 37) printf("Percent");
    else if (i == 38) printf("Ampersand");
    else if (i == 39) printf("Single quote");
    else if (i == 40) printf("Left parenthesis");
    else if (i == 41) printf("Right parenthesis");
    else if (i == 42) printf("Asterisk");
    else if (i == 43) printf("Plus");
    else if (i == 44) printf("Comma");
    else if (i == 45) printf("Hyphen/Minus");
    else if (i == 46) printf("Period");
    else if (i == 47) printf("Forward slash");
    else if (i >= 48 && i <= 57) printf("Digit");
    else if (i == 58) printf("Colon");
    else if (i == 59) printf("Semicolon");
    else if (i == 60) printf("Less than");
    else if (i == 61) printf("Equals sign");
    else if (i == 62) printf("Greater than");
    else if (i == 63) printf("Question mark");
    else if (i == 64) printf("At sign");
    else if (i >= 65 && i <= 90) printf("Uppercase letter");
    else if (i == 91) printf("Left square bracket");
    else if (i == 92) printf("Backslash");
    else if (i == 93) printf("Right square bracket");
    else if (i == 94) printf("Caret");
    else if (i == 95) printf("Underscore");
    else if (i == 96) printf("Grave accent");
    else if (i >= 97 && i <= 122) printf("Lowercase letter");
    else if (i == 123) printf("Left curly brace");
    else if (i == 124) printf("Vertical bar");
    else if (i == 125) printf("Right curly brace");
    else if (i == 126) printf("Tilde");
    else if (i >= 32 && i <= 126) printf("Symbol");
    else if (i == 127) printf("Delete");
    else if (i >= 128 && i <= 144) printf("Control character");
    else if (i == 145) printf("Left single quotation mark");
    else if (i == 146) printf("Right single quotation mark");
    else if (i == 147) printf("Left double quotation mark");
    else if (i == 148) printf("Right double quotation mark");
    else if (i == 149) printf("Bullet");
    else if (i == 150) printf("En dash");
    else if (i == 151) printf("Em dash");
    else if (i == 152) printf("Small tilde");
    else if (i == 153) printf("Trade mark sign");
    else if (i >= 154 && i <= 159) printf("Control character");
    else if (i == 160) printf("Non-breaking space");
    else if (i == 161) printf("Inverted exclamation mark");
    else if (i == 162) printf("Cent sign");
    else if (i == 163) printf("Pound sign");
    else if (i == 164) printf("Currency sign");
    else if (i == 165) printf("Yen sign");
    else if (i == 166) printf("Broken bar");
    else if (i == 167) printf("Section sign");
    else if (i == 168) printf("Diaeresis");
    else if (i == 169) printf("Copyright sign");
    else if (i == 170) printf("Feminine ordinal indicator");
    else if (i == 171) printf("Left-pointing double angle quotation mark");
    else if (i == 172) printf("Not sign");
    else if (i == 173) printf("Soft hyphen");
    else if (i == 174) printf("Registered sign");
    else if (i == 175) printf("Macron");
    else if (i == 176) printf("Degree sign");
    else if (i == 177) printf("Plus-minus sign");
    else if (i == 178) printf("Superscript two");
    else if (i == 179) printf("Superscript three");
    else if (i == 180) printf("Acute accent");
    else if (i == 181) printf("Micro sign");
    else if (i == 182) printf("Paragraph sign");
    else if (i == 183) printf("Middle dot");
    else if (i == 184) printf("Cedilla");
    else if (i == 185) printf("Superscript one");
    else if (i == 186) printf("Masculine ordinal indicator");
    else if (i == 187) printf("Right-pointing double angle quotation mark");
    else if (i == 188) printf("Vulgar fraction one quarter");
    else if (i == 189) printf("Vulgar fraction one half");
    else if (i == 190) printf("Vulgar fraction three quarters");
    else if (i == 191) printf("Inverted question mark");
    else if (i == 192) printf("Capital A with grave accent");
    else if (i == 193) printf("Capital A with acute accent");
    else if (i == 194) printf("Capital A with circumflex accent");
    else if (i == 195) printf("Capital A with tilde");
    else if (i == 196) printf("Capital A with diaeresis");
    else if (i == 197) printf("Capital A with ring above");
    else if (i == 198) printf("Capital AE ligature");
    else if (i == 199) printf("Capital C with cedilla");
    else if (i == 200) printf("Capital E with grave accent");
    else if (i == 201) printf("Capital E with acute accent");
    else if (i == 202) printf("Capital E with circumflex accent");
    else if (i == 203) printf("Capital E with diaeresis");
    else if (i == 204) printf("Capital I with grave accent");
    else if (i == 205) printf("Capital I with acute accent");
    else if (i == 206) printf("Capital I with circumflex accent");
    else if (i == 207) printf("Capital I with diaeresis");
    else if (i == 208) printf("Capital Eth");
    else if (i == 209) printf("Capital N with tilde");
    else if (i == 210) printf("Capital O with grave accent");
    else if (i == 211) printf("Capital O with acute accent");
    else if (i == 212) printf("Capital O with circumflex accent");
    else if (i == 213) printf("Capital O with tilde");
    else if (i == 214) printf("Capital O with diaeresis");
    else if (i == 215) printf("Multiplication sign");
    else if (i == 216) printf("Capital O with stroke");
    else if (i == 217) printf("Capital U with grave accent");
    else if (i == 218) printf("Capital U with acute accent");
    else if (i == 219) printf("Capital U with circumflex accent");
    else if (i == 220) printf("Capital U with diaeresis");
    else printf("Extended ASCII");
    printf("\n");
    if (i == 255) break; // Limit to 256 characters
  }
}

int main() {
  print_ascii_table();
  return 0;
}