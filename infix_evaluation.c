#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

int power(int a, int b);  //#include <math.h>

int main(int argc, char *argv[]) {
  char *a = argv[1];
  int i, N = strlen(a), num, temp, var1, var2;
  
  Stack *operands, *operators;
  operands->N = N;
  operators->N = N;
  STACKinit(N, operands);
  STACKinit(N, operators);
  
  for (i = 0; i < N; i++) {
    if ((a[i] >= '0') && (a[i] <= '9')) {
      num = 0;
      while ((a[i] >= '0') && (a[i] <= '9')) {
        num *= 10;
        num += a[i];
        i++;
      }
      STACKpush(num, operands);
    }
    else if (a[i] == '(') {
      STACKpush(a[i], operators);
    }
    else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%' || a[i] == '^') {
      temp = STACKpop(operators);
      switch(temp) {
        case '+':
          if (a[i] == '+' || a[i] == '-') {
            var2 = STACKpop(operands);
            var1 = STACKpop(operands);
            STACKpush(var1 + var2, operands);
          }
          else STACKpush(temp, operators); 
          break;
        case '-':
          if (a[i] == '+' || a[i] == '-') {
            var2 = STACKpop(operands);
            var1 = STACKpop(operands);
            STACKpush(var1 - var2, operands);
          }
          else STACKpush(temp, operators); 
          break;
        case '*':
          if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%') {
            var2 = STACKpop(operands);
            var1 = STACKpop(operands);
            STACKpush(var1 * var2, operands);
          }
          else STACKpush(temp, operators); 
          break;
        case '/':
          if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%') {
            var2 = STACKpop(operands);
            var1 = STACKpop(operands);
            STACKpush(var1 / var2, operands);
          }
          else STACKpush(temp, operators); 
          break;
        case '%':
          if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%') {
            var2 = STACKpop(operands);
            var1 = STACKpop(operands);
            STACKpush(var1 % var2, operands);
          }
          else STACKpush(temp, operators); 
          break;
        case '^':
          var2 = STACKpop(operands);
          var1 = STACKpop(operands);
          STACKpush(power(var1, var2), operands);
          break;
        default:
          printf("Syntax Error!\n");
          return;
      }
    }
    else if (a[i] == ')') do {
      temp = STACKpop(operators);
      switch(temp) {
        case '+':
          if (a[i] == '+' || a[i] == '-') {
            var2 = STACKpop(operands);
            var1 = STACKpop(operands);
            STACKpush(var1 + var2, operands);
          }
          else STACKpush(temp, operators); 
          break;
        case '-':
          if (a[i] == '+' || a[i] == '-') {
            var2 = STACKpop(operands);
            var1 = STACKpop(operands);
            STACKpush(var1 - var2, operands);
          }
          else STACKpush(temp, operators); 
          break;
        case '*':
          if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%') {
            var2 = STACKpop(operands);
            var1 = STACKpop(operands);
            STACKpush(var1 * var2, operands);
          }
          else STACKpush(temp, operators); 
          break;
        case '/':
          if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%') {
            var2 = STACKpop(operands);
            var1 = STACKpop(operands);
            STACKpush(var1 / var2, operands);
          }
          else STACKpush(temp, operators); 
          break;
        case '%':
          if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%') {
            var2 = STACKpop(operands);
            var1 = STACKpop(operands);
            STACKpush(var1 % var2, operands);
          }
          else STACKpush(temp, operators); 
          break;
        case '^':
          var2 = STACKpop(operands);
          var1 = STACKpop(operands);
          STACKpush(power(var1, var2), operands);
          break;
        default:
          printf("Syntax Error!\n");
          return;
      }
    } while (a[i] == '(');
    else {
      printf("Syntax Error!\n");
      return;
    }
  }
  //Else (no more character left to read):
  while (!STACKempty(operators)) {
    temp = STACKpop(operators);
    if (STACKempty(operands)) {
      printf("Syntax Error!\n");
      return;
    }
    var2 = STACKpop(operands);
    if (STACKempty(operands)) {
      printf("Syntax Error!\n");
      return;
    }
    var1 = STACKpop(operands);
    switch(temp) {
      case '+':
        if (a[i] == '+' || a[i] == '-') {
          var2 = STACKpop(operands);
          var1 = STACKpop(operands);
          STACKpush(var1 + var2, operands);
        }
        else STACKpush(temp, operators); 
        break;
      case '-':
        if (a[i] == '+' || a[i] == '-') {
          var2 = STACKpop(operands);
          var1 = STACKpop(operands);
          STACKpush(var1 - var2, operands);
        }
        else STACKpush(temp, operators); 
        break;
      case '*':
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%') {
          var2 = STACKpop(operands);
          var1 = STACKpop(operands);
          STACKpush(var1 * var2, operands);
        }
        else STACKpush(temp, operators); 
        break;
      case '/':
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%') {
          var2 = STACKpop(operands);
          var1 = STACKpop(operands);
          STACKpush(var1 / var2, operands);
        }
        else STACKpush(temp, operators); 
        break;
      case '%':
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%') {
          var2 = STACKpop(operands);
          var1 = STACKpop(operands);
          STACKpush(var1 % var2, operands);
        }
        else STACKpush(temp, operators); 
        break;
      case '^':
        var2 = STACKpop(operands);
        var1 = STACKpop(operands);
        STACKpush(power(var1, var2), operands);
        break;
      default:
        printf("Syntax Error!\n");
        return;
    }
  }
}

int power(int a, int b) {
  int i;
  for (i = 1; i <= b; i++) {
    i *= a;
  }
  return i;
}
