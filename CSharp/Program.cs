using System; //기본 클래스의 이름공간
using static System.Console; //정적 멤버를 사용하겠다.

namespace BrainCSharp //성격, 하는 일이 비슷한 형식을 하나의 이름으로 그룹화
{
    class HelloWorld
    {
        // 프로그램 실행이 시작되는 곳
        static void Main(string[] args) //메소드(함수)
        {
            if (args.Length == 0)
            {
                Console.WriteLine("사용법 : HelloWorld.exe <이름>"); //메소드
                return;
            }

            WriteLine("Hello, {0}!", args[0]); // Hello, World를 프롬프트에 출력
        }
    }
}
