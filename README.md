# task3mak
task 3, Makarova, OS Lab

Функция input_str_check проводит предварительную проверку введеннной строки. Во-первых, проверяется длина, т.к. из формы грамматики видно, что ей удовлетворяют строки только длиной 2 символа. Во-вторых, проводится проверка на допустимые символы: терминалы данной грамматики "0", "1" и "2". 
Данная функция возвращает тип int, 0 если строка прошла проверку успешно, -1 - если обнаружено несоответствие. В последнем случае в лог-файл записывается сообщение об ошибке. Аргументами input_str_check являются входная строка и имя лог-файла в виде ссылок.
