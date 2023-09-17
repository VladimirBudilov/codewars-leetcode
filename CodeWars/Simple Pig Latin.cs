using System.Text.RegularExpressions;

namespace CodeWars;

public class Simple_Pig_Latin
{
    public static string PigIt(string str)
    {
        var strWorker = str.Split(" ");
        string answer = "";
        for (int index = 0; index < strWorker.Length; index++)
        {
            if (Regex.IsMatch(strWorker[index], "[a-z]", RegexOptions.IgnoreCase))
            {
                answer += strWorker[index][1..] + strWorker[index][0] + "ay";
                if (index != strWorker.Length - 1)
                    answer += " ";
            }
            else
                answer += strWorker[index];
        }

        return answer;
    }
}