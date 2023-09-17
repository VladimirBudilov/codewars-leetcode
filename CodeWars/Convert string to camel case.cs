namespace CodeWars;

public class Convert_string_to_camel_case
{
    
    public static string ToCamelCase(string str)
    {
        var lst = new List<char>();
        for (int i = 0; i < str.Length; i++)
        {
            if (str[i] == '_' || str[i] == '-')
            {
                lst.Add(char.ToUpper(str[++i]));
                continue;
            }
            lst.Add(str[i]);
        }
        return string.Join("", lst);
    }
}
