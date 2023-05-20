namespace LeetCode;

public class Roman_to_Integer
{
    public int RomanToInt(string s)
    {
        var result = 0;

        // 1. Create a dictionary of Roman numerals
        Dictionary<char, int> dictionary = new()
        {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };

        // 2. Loop through the string
        for (int i = 0; i < s.Length - 1; i++)
        {
            // 3. If the current character is less than the next character, subtract it from the result
            if (i + 1 < s.Length && dictionary[s[i]] < dictionary[s[i + 1]])
                result -= dictionary[s[i]];
            // 4. Otherwise, add it to the result
            else
                result += dictionary[s[i]];
        }
        
        // 5. Add the last character to the result
        return result += dictionary[s[^1]];
    }
}