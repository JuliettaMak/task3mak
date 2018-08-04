# task3mak
task 3, Makarova, OS Lab

В лог-файл выводятся:
  время запуска программы;
  введенная пользователем в командной строке строка;
  таблица:  1я колонка - номер прохода по строке. Проход осуществляется в цикле while слева направо, т.к. LR(0) - левосторонний анализатор.
            2я колонка - строка после применения правила;
            далее информация о произведенном преобразовании.
 SUCCESS - если осуществилась свертка к целевому символу S; FAILURE - если свертка к целевому символу S невозможна. И в этой же строке выводится финальный вид рассматриваемый строки после всех преобразований.
После ввода и проверки строки к ней в конец прибавляется символ F для метки конца строки. 

Функция input_str_check проводит предварительную проверку введеннной строки. Во-первых, проверяется длина, т.к. из формы грамматики видно, что ей удовлетворяют строки только длиной 2 символа. Во-вторых, проводится проверка на допустимые символы: терминалы данной грамматики "0", "1" и "2". Данная функция возвращает тип int, 0 если строка прошла проверку успешно, -1 - если обнаружено несоответствие. В последнем случае в лог-файл записывается сообщение об ошибке. Аргументами input_str_check являются входная строка и имя лог-файла в виде ссылок.

Функция reduce заменяет указанные терминалы в строке на нетерминалы согласна правилам грамматики. Сохраняет в лог-файл информацию о текущем состоянии строки и произведенном преобразовании. Аргументы функции - * inp указатель на массив char, т.е. на строку; str_len его длина; ind индекс терминала в строке, который заменяется по правилу;  jj - номер прохода по строке; num - количество сокращаемых терминалов; nonterminal - имя правила (S или B); * filename - имя лог-файла в виде ссылки.

Сравнение анализаторов:
Для грамматики данного вида алгоритмы LR(0) и LR(1) дают одинаковые результаты, т.к. каждому терминалу соответствует единственное действие. Для более сложных грамматик, в которых возможна неоднозначность действия для одного символа reduce или shift, следует использовать  анализатор LR(1), т.к. LR(1) может разбирать любую контекстно-свободную однозначную грамматику.
SLR, так же как и LR(0) имеет узкую область применения, т.е. способен разобрать лишь небольшой класс грамматик. LALR(1) - обобщение SLR, способен разобрать более широкий класс грамматик. GLR-парсер является самым универсальным, т.к. он может разрешать неоднозначность и недетминированность, он обрабатывает все возможные трактовки входной последовательности.
