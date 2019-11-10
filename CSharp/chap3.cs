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
//namespace IntegralConversion
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            sbyte a = 127;
//            Console.WriteLine(a);

//            int b = (int)a;
//            Console.WriteLine(b); //작은 공간 -> 큰 공간

//            int x = 128; // sbyte의 최대값 127보다 1 큰 수 
//            Console.WriteLine(x);

//            sbyte y = (sbyte)x;
//            Console.WriteLine(y); //큰 공간 -> 작은 공간
//        }
//    }
//}

//13
//namespace FloatConversion
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            float a = 69.6875f;
//            Console.WriteLine("a : {0}", a);

//            double b = (double)a;
//            Console.WriteLine("b : {0}", b);

//            Console.WriteLine("69.6875 == b : {0}", 69.6875 == b); //4째 자리까지는 괜찮은데...

//            float x = 0.1f;
//            Console.WriteLine("x : {0}", x);

//            double y = (double)x;
//            Console.WriteLine("y : {0}", y);

//            Console.WriteLine("0.1 == y : {0}", 0.1 == y); //첫째 자리는 double형으로 변환하니 정밀성에서 문제 생김
//        }
//    }
//}

//14
//namespace SignedUnsignedConversion
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            int a = 500;
//            Console.WriteLine(a);

//            uint b = (uint)a;
//            Console.WriteLine(b);

//            int x = -30;
//            Console.WriteLine(x);

//            uint y = (uint)x;
//            Console.WriteLine(y);
//        }
//    }
//}

//15
//namespace FloatToIntegral
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            float a = 0.9f;
//            int b = (int)a;
//            Console.WriteLine(b);

//            float c = 1.1f;
//            int d = (int)c;
//            Console.WriteLine(d);
//        }
//    }
//}


//16
//namespace StringNumberConversion
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            int a = 123;
//            string b = a.ToString(); //ToString() 메소드
//            Console.WriteLine(b);

//            float c = 3.14f;
//            string d = c.ToString();
//            Console.WriteLine(d);

//            string e = "123456";
//            int f = Convert.ToInt32(e); //Convert.ToInt32() 메소드, string -> int
//            Console.WriteLine(f);

//            string g = "1.2345";
//            float h = float.Parse(g); //string -> float
//            Console.WriteLine(h);
//        }
//    }
//}

//17
//namespace Constant
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            const int MAX_INT = 2147483647;
//            const int MIN_INT = -2147483648;

//            Console.WriteLine(MAX_INT);
//            Console.WriteLine(MIN_INT);
//        }
//    }
//}

//18
//namespace Enum
//{
//    class MainApp
//    {
//        enum DialogResult { YES, NO, CANCEL, CONFIRM, OK }

//        static void Main(string[] args)
//        {
//            Console.WriteLine((int)DialogResult.YES);
//            Console.WriteLine((int)DialogResult.NO);
//            Console.WriteLine((int)DialogResult.CANCEL);
//            Console.WriteLine((int)DialogResult.CONFIRM);
//            Console.WriteLine((int)DialogResult.OK);
//        }
//    }
//}

//19
//namespace Enum2
//{
//    class MainApp
//    {
//        enum DialogResult { YES, NO, CANCEL, CONFIRM, OK }

//        static void Main(string[] args)
//        {
//            DialogResult result = DialogResult.YES; //DialogResult는 열거형 변수 및 새로운 자료형

//            Console.WriteLine(result == DialogResult.YES);
//            Console.WriteLine(result == DialogResult.NO);
//            Console.WriteLine(result == DialogResult.CANCEL);
//            Console.WriteLine(result == DialogResult.CONFIRM);
//            Console.WriteLine(result == DialogResult.OK);
//        }
//    }
//}

//20
//namespace Enum3
//{
//    class MainApp
//    {
//        enum DialogResult { YES = 10, NO, CANCEL, CONFIRM = 50, OK }

//        static void Main(string[] args)
//        {
//            Console.WriteLine((int)DialogResult.YES); //10
//            Console.WriteLine((int)DialogResult.NO); //11
//            Console.WriteLine((int)DialogResult.CANCEL); //12
//            Console.WriteLine((int)DialogResult.CONFIRM); //50
//            Console.WriteLine((int)DialogResult.OK); //51
//        }
//    }
//}

//21
//namespace Nullalble
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            int? a = null; //데이터 형식? 변수이름

//            Console.WriteLine(a.HasValue); //모든 nullable 변수는 HasValue 속성(Attribute)를 가진다. 
//            Console.WriteLine(a != null);

//            a = 3;

//            Console.WriteLine(a.HasValue);
//            Console.WriteLine(a != null);
//            Console.WriteLine(a.Value);
//        }
//    }
//}

//22
//컴파일러가 변수 자료형을 알아서 결정해준다.
//하지만, 변수 선언과 동시에 초기화 해줘야 한다.
//지역변수로만 사용한다.
//namespace UsingVar
//{
//    class MainApp
//    {
//        static void Main(string[] args)
//        {
//            var a = 20;
//            Console.WriteLine("Type: {0}, Value: {1}", a.GetType(), a);

//            var b = 3.1414213;
//            Console.WriteLine("Type: {0}, Value: {1}", b.GetType(), b);

//            var c = "Hello, World!";
//            Console.WriteLine("Type: {0}, Value: {1}", c.GetType(), c);

//            var d = new int[] { 10, 20, 30 };
//            Console.Write("Type: {0}, Value: ", d.GetType());
//            foreach (var e in d)
//                Console.Write("{0} ", e);

//            Console.WriteLine();
//        }
//    }
//}

//23
//C#의 데이터 형식 체계는 .NET 기반 언어들 모두가 사용가능하다.
//공용형식 시스템(CTS)
namespace CTS
{
    class MainApp
    {
        static void Main(string[] args)
        {
            System.Int32 a = 123; //공용형식 시스템에서 정의된 데이터 형식
            int b = 456;

            Console.WriteLine("a type:{0}, value:{1}", a.GetType().ToString(), a);
            Console.WriteLine("b type:{0}, value:{1}", b.GetType().ToString(), b);

            System.String c = "abc"; //공용형식 시스템에서 정의된 데이터 형식
            string d = "def";

            Console.WriteLine("c type:{0}, value:{1}", c.GetType().ToString(), c);
            Console.WriteLine("d type:{0}, value:{1}", d.GetType().ToString(), d);
        }
    }
}