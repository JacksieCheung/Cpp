#include <cstdio>
#include <cstring>

static const int LEN = 2600;

int a[LEN], b[LEN], c[LEN], tmp[LEN], res[LEN];

void clear(int a[])
{
  for (int i = 0; i < LEN; ++i)
    a[i] = 0;
}

void read(int a[])
{
  static char s[LEN + 1];
  scanf("%s", s);

  clear(a);

  int len = strlen(s);
  for (int i = 0; i < len; ++i)
    a[len - i - 1] = s[i] - '0';
}

void print(int a[])
{
  int i;
  for (i = LEN - 1; i >= 1; --i)
    if (a[i] != 0)
      break;
  for (; i >= 0; --i)
    putchar(a[i] + '0');
  putchar('\n');
}

// 加法运算
void add(int a[], int b[], int c[])
{
  clear(c);

  for (int i = 0; i < LEN - 1; ++i)
  {
    c[i] += a[i] + b[i];
    if (c[i] >= 10)
    {
      // 直接在前一位加上1就可以了
      // 因为数组有预留，也不怕越界
      c[i + 1] += 1;
      c[i] -= 10;
    }
  }
}

// 减法运算
// 只能处理 a>b 的情况
// 要 a<b 需要换过来传值，然后输出的时候加个负号
void sub(int a[], int b[], int c[])
{
  clear(c);

  for (int i = 0; i < LEN - 1; ++i)
  {
    c[i] += a[i] - b[i];
    if (c[i] < 0)
    {
      c[i + 1] -= 1;
      c[i] += 10;
    }
  }
}

// 高精度-单精度乘法
void mul_short(int a[], int b, int c[])
{
  clear(c);

  for (int i = 0; i < LEN - 1; ++i)
  {
    // 直接把 a 的第 i 位数码乘以乘数，加入结果
    c[i] += a[i] * b;

    if (c[i] >= 10)
    {
      // 处理进位
      // c[i] / 10 即除法的商数成为进位的增量值
      c[i + 1] += c[i] / 10;
      // 而 c[i] % 10 即除法的余数成为在当前位留下的值
      c[i] %= 10;
    }
  }
}

// 双高精度乘法运算
void mul(int a[], int b[], int c[])
{
  clear(c);

  for (int i = 0; i < LEN - 1; ++i)
  {
    // 这里直接计算结果中的从低到高第 i 位，且一并处理了进位
    // 第 i 次循环为 c[i] 加上了所有满足 p + q = i 的 a[p] 与 b[q] 的乘积之和
    // 这样做的效果和直接进行上图的运算最后求和是一样的，只是更加简短的一种实现方式
    for (int j = 0; j <= i; ++j)
      c[i] += a[j] * b[i - j];

    if (c[i] >= 10)
    {
      c[i + 1] += c[i] / 10;
      c[i] %= 10;
    }
  }
}

bool isAOne(int a[])
{
  int i;
  for (i = LEN - 1; i >= 0; --i)
    if (a[i] != 0)
      break;
  if (i == 0 && a[0] == 1)
  {
    return true;
  }

  return false;
}

void copy(int src[], int dest[])
{
  for (int i = 0; i < LEN; i++)
  {
    dest[i] = src[i];
  }
}

// 实现阶乘
void func(int a[], int b[], int c[], int tmp[], int res[], int num)
{
  mul_short(tmp, num, res);
  while (num != 1)
  {
    num--;
    mul_short(res, num, c); // res = a*b
    copy(c, res);
  }
}

int main()
{
  int num = 0;
  printf("样例输入：");
  scanf("%d", &num);
  clear(tmp);
  clear(res);
  tmp[0] = 1;

  func(a, b, c, tmp, res, num);

  printf("样例输出：\n");
  print(res);

  return 0;
}