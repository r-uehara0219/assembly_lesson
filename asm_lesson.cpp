#include <bits/stdc++.h>
using namespace std;

int main()
{
  string str1 = "Bjarne ";
  string str2 = "Stroustrup";
  string ret;
  __asm__ __volatile__(
      "lea rsi, [eax]"
      "call loop_copy"
      "mov rdi, rax"

      "lea rsi, [ebx]"
      "call loop_copy"

      "ret"

      "loop_copy:"
      "  movsb"
      "  cmp byte[rdi - 1], 0"
      "  je copy_to_rax"
      "  jmp loop_copy"
      "copy_to_rax:"
      "  lea %0, [rdi - 1]"
      "  ret"
      : "=r"(ret)
      : "a"(str1), "b"(str2));
  cout << ret << endl;
}
