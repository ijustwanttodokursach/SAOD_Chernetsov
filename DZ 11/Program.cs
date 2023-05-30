using System;
using System.Text.RegularExpressions;
using System.IO;
using System.Xml;


namespace RegExpLab
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = " фыидо, fjbld33- 2олт? я3рabc abёёcd";
            Console.WriteLine(str);

            //Regex re = new Regex(@"\w*\d\w*"); //регулярное выражение, которое соответствует любому слову, включающему хотя бы одну цифру
            //Regex re = new Regex(@"\b\w*(\w)\1\w*\b"); // слова со двоенными символами
            //Regex re = new Regex(@"\b[a-zA-Z0-9]+\b"); // слова с латинскими буквами и цифрами
            //Regex re = new Regex(@"\b\w*[a-zA-Z]\w*\b"); // слова с хотя бы одной латинской буквой
            //Regex re = new Regex(@"\b\w*[a-zA-Z]\w*\b");
            //MatchCollection mc = re.Matches(str);
            //foreach (var m in mc) 
            //    Console.WriteLine(m);

            string orig;
            try
            {
                using (StreamReader sr = new StreamReader("Dictionary.xml"))
                {
                    orig = sr.ReadToEnd();
                    Console.WriteLine(orig.Length);
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка чтения файла: \"Dictionary.xml\"\n{0}", ex);
                return;
            }
            Regex re = new Regex(@"<([a-zA-Z0-9]+)>[^<]*([a-zA-Z0-9а-яA-Я]+)<\/[a-zA-Z0-9]+>");

            MatchCollection mc = re.Matches(orig);
            foreach (var m in mc) 
                Console.WriteLine(m);
        }
    }
}
