using System.Text;

public class LongestConsecutives 
{
    public static string LongestConsec(string[] strarr, int k) 
    {
        if(strarr.Length == 0 || strarr.Length < k || k <= 0) return "";
        var answer = String.Empty;
        for (int i = k-1; i < strarr.Length; i++)
        {
            var temp = new List<string>();
            for (int j = 0; j < k; j++)
            {
                temp.Add(strarr[i - j]);
            }
            temp.Reverse();
            var sb = new StringBuilder();
            foreach (var tem in temp)
            {
                sb.Append(tem);
            }
            if (answer.Length < sb.ToString().Length)
            {
                answer = sb.ToString();
            }
        }
        return answer;
    }
}