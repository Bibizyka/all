package myproject;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import javax.swing.SwingUtilities;

class MyProject {
    
    public static void main(String[] args)
	{
            try{
                File file = new File( "text.txt" );
                String text="";
                BufferedReader br = new BufferedReader (
                   new InputStreamReader(
                       new FileInputStream( file ), "Cp1251"
                   )
                );
                
                // Считываем в строку текстовый файл со всем его содержимым
                String line = "";
                while ((line = br.readLine()) != null) {
                    text=text+line;
                }
                br.close();
                
                System.out.println("ТЕКСТ:\n"+text);
                
                
                System.out.println("Введите слово: \n");
                String slovo = null;
                Scanner sc= new Scanner(System.in,"Cp1251");
                slovo = sc.nextLine();
                sc.close();
                
                
                System.out.println("Выводим только предложение, включающие в себя это слово:");
                int i = 0; // Счетчик, который проходит по тексту, считывание за 1 проход
                for (; i<text.length(); i++)
		{
			String buffer = "";// Строка, в которую на всякий случай считываем предложение
                        // Считываем предложение, пока не прочитали до точки
                        boolean find = false;// Флаг - что мы нашли это слово, значит, что нужно вывести предложение
                        while(i<text.length() && text.charAt(i)!='.')
                        {
                            buffer=buffer+text.charAt(i);
                            int j=0;// Счетчик, который будет бегать по нашему слову
                            // По ходу считывания проверяем на вхождение нашего слове
                            if((int)text.charAt(i)==(int)slovo.charAt(j))
                            {
                                System.out.println(text.charAt(i)+" "+slovo.charAt(0));
                                i+=1; j+=1;
                                while(i<text.length() && j<slovo.length() && (int)text.charAt(i)==(int)slovo.charAt(j))
                                {
                                     buffer=buffer+text.charAt(i);
                                     i++;
                                     j++;
                                }
                                // Если мы прочитали наше слово, то ставим флаг в положительное значение!
                                if (j==slovo.length())
                                    find=true;
                                
                            }
                            
                            i++;
                        }
                        // Если нашли слово в предложении - выведем его
                        if (find)
                            System.out.println(buffer);
		}
                
                
                System.out.println("КОНЕЦ");
                
            }
            catch(IOException e)
            {
                System.out.println(e.getLocalizedMessage()+" Данный файл не найден");
            }
	}    
}

