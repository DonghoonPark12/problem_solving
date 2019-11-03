using System;

//1
//namespace IntegralTypes
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            sbyte a = -10;
//            byte b = 40;

//            Console.WriteLine($"a={a}, b={b}");

//            short c = -30000;
//            ushort d = 60000;

//            Console.WriteLine($"c={c}, d={d}");

//            int e = -1000000; // 0이 7개 
//            uint f = 300000000; // 0이 8개 

//            Console.WriteLine($"e={e}, f={f}");

//            long g = -500000000000; // 0이 11개 
//            ulong h = 2000000000000000000; // 0이 18개 

//            Console.WriteLine($"g={g}, h={h}");
//        }
//    }
//}

//2
//namespace IntegralLiterals
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            byte a = 240;          // 10진수 리터럴
//            Console.WriteLine($"a={a}");

//            byte b = 0b11110000; // 2진수 리터럴
//            Console.WriteLine($"b={b}");

//            byte c = 0XF0;        // 16진수 리터럴
//            Console.WriteLine($"c={c}");

//            uint d = 0x1234abcd; // 16진수 리터럴
//            Console.WriteLine($"d={d}");
//        }
//    }
//}

//3
//namespace SignedUnsigned
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            byte a = 255; //1111 1111 , unsigned byte
//            sbyte b = (sbyte)a; //(1)111 1111, signed byte

//            Console.WriteLine(a);
//            Console.WriteLine(b);
//        }
//    }
//}

//4
//namespace Overflow
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            uint a = uint.MaxValue; //11111111 11111111 11111111 11111111 

//            Console.WriteLine(a);

//            a = a + 1;

//            Console.WriteLine(a);
//        }
//    }
//}

//5
//namespace FloatingPoint //소수점이 고정되어 있지 않고 움직이면서 수 표현.
//{                       //산술 연산 과정이 정수계열 형식보다 복잡해 느림.
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            float a = 3.14159265358979323846f; //4바이트 = 1비트(부호), 8비트(지수부, 소수점 위치 표현), 23비트(가수부, 수를 표현).
//            Console.WriteLine(a);

//            double b = 3.14159265358979323846; //float 보다 높은 정밀도
//            Console.WriteLine(b);

//        }
//    }
//}

//6
//namespace Decimal //29자리 데이터를 표현할 수 있는 소수 형식
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            float a = 3.141592653589793238462643383279f;
//            double b = 3.141592653589793238462643383279;
//            decimal c = 3.141592653589793238462643383279m;

//            Console.WriteLine(a);
//            Console.WriteLine(b);
//            Console.WriteLine(c);
//        }
//    }
//}

//7
//namespace Char
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            char a = '안';
//            char b = '녕';
//            char c = '하';
//            char d = '세';
//            char e = '요';

//            Console.Write(a); //WriteLine과 달리 개행을 하지 않는다. 
//            Console.Write(b);
//            Console.Write(c);
//            Console.Write(d);
//            Console.Write(e);
//            Console.WriteLine();
//        }
//    }
//}

//8
//namespace String
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            string a = "안녕하세요?";
//            string b = "박상현입니다.";

//            Console.WriteLine(a);
//            Console.WriteLine(b);
//        }
//    }
//}


//9
//namespace Bool
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            bool a = true;
//            bool b = false;

//            Console.WriteLine(a);
//            Console.WriteLine(b);
//        }
//    }
//}


//10
/*
 Object를 모든 데이터 형식의 조상, 상속 해주는 조상.
 참조형식, 힙에 데이터 할당.
 */
//namespace Object //c++에 없는 자료형
//{
//    class Program
//    {
//        static void Main(string[] args)
//        {
//            object a = 123;
//            object b = 3.141592653589793238462643383279m;
//            object c = true;
//            object d = "안녕하세요.";

//            Console.WriteLine(a);
//            Console.WriteLine(b);
//            Console.WriteLine(c);
//            Console.WriteLine(d);
//        }
//    }
//}


//11
//namespace BoxingUnboxing
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            int a = 123;
//            object b = (object)a;   // a의 담긴 값을 박싱해서 힙에 저장, ★ heap에 123이 저장된다. b는 힙에 저장된 123을 가리키고 있다. 
//            int c = (int)b;         // b에 담긴 값을 언박싱해서 스택에 저장, 박싱된 123을 언박싱해서 stack에 저장.

//            Console.WriteLine(a);
//            Console.WriteLine(b);
//            Console.WriteLine(c);

//            double x = 3.1414213;
//            object y = x;           // x에 담긴 값을 박싱해서 힙에 저장 
//            double z = (double)y;   // y에 담긴 값을 언박싱해서 스택에 저장 

//            Console.WriteLine(x);
//            Console.WriteLine(y);
//            Console.WriteLine(z);
//        }
//    }
//}

//12
