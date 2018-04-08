#include "coder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int encode(uint32_t code_point, CodeUnits *code_units) {

  int bits = 0;
  int helper = 0;
  code_units->length = 0;
  for (int i = 0; i < MaxCodeLength; i++) {
    code_units->code[i] = code_units->code[i] & 0;
  }

  for (uint32_t i = 1; i != 0; i = i << 1) {

    helper++;
    if ((code_point & i) != 0) {

      bits = helper;
    }
  }

  if (bits > 21) {
    printf("\nWe can`t encode this number\n");
    return -1;
  }

  if (bits <= 7) {
    code_units->length = 1;

  } else if (bits > 7 && bits <= 11) {
    code_units->length = 2;

  } else if (bits > 11 && bits <= 16) {
    code_units->length = 3;

  } else if (bits > 16 && bits <= 21) {
    code_units->length = 4;
  }

  if (code_units->length == 1) {
    code_units->code[0] = code_point & 0x7F;
  } else if (code_units->length == 2) {
    code_units->code[0] = ((code_point >> 6) & 0x1F) | 0xC0;
    code_units->code[1] = (code_point & 0x3F) | 0x80;

  } else if (code_units->length == 3) {
    code_units->code[0] = ((code_point >> 12) & 0xF) | 0xE0;
    code_units->code[1] = ((code_point >> 6) & 0x3F) | 0x80;
    code_units->code[2] = (code_point & 0x3F) | 0x80;

  } else if (code_units->length == 4) {
    code_units->code[0] = ((code_point >> 18) & 0x7) | 0xF0;
    code_units->code[1] = ((code_point >> 12) & 0x3F) | 0x80;
    code_units->code[2] = ((code_point >> 6) & 0x3F) | 0x80;
    code_units->code[3] = (code_point & 0x3F) | 0x80;
  }

  return 0;
}

uint32_t decode(const CodeUnits *code_units) {
  uint32_t code_point = 0;

  if (code_units->length == 1) {
    code_point = code_point | code_units->code[0];
  } else if (code_units->length == 2) {
    for (int i = 0; i < code_units->length; i++) {
      if (i == 0) {
        code_point = code_point | (code_units->code[i] & 0x1F);
      } else {
        code_point = code_point << 6;
        code_point = code_point | (code_units->code[i] & 0x3F);
      }
    }
  } else if (code_units->length == 3) {
    for (int i = 0; i < code_units->length; i++) {
      if (i == 0) {
        code_point = code_point | (code_units->code[i] & 0xF);
      } else {
        code_point = code_point << 6;
        code_point = code_point | (code_units->code[i] & 0x3F);
      }
    }
  } else if (code_units->length == 4) {
    for (int i = 0; i < code_units->length; i++) {
      if (i == 0) {
        code_point = code_point | (code_units->code[i] & 0x7);
      } else {
        code_point = code_point << 6;
        code_point = code_point | (code_units->code[i] & 0x3F);
      }
    }
  }

  return code_point;
}
