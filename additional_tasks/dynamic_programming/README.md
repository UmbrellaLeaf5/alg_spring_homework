# Алёна и таблички

На уроке информатики Алёна осваивает редактирование таблиц в одной очень известной программе.

Сейчас у неё есть таблица из целых чисел, состоящая из n строк и m столбцов. Через a[i][j] будем обозначать число в i-й строке и j-м столбце. Будем говорить, что таблица отсортирована по неубыванию по j-му столбцу, если a[i][j] ≤ a[i+1][j] для всех i от 1 до n - 1.

Учительница дала Алёне k заданий. Для каждого из заданий известны два числа l и r и требуется ответить на вопрос: если от таблицы оставить только строки с l по r включительно, то будет ли она отсортирована по неубыванию хотя бы по одному столбцу? Другими словами, существует ли такое j, 
что a[i][j] ≤ a[i+1][j] для всех i от l до r - 1 включительно.

# Входные данные
Даны два целых положительных числа n и m (1 ≤ n·m ≤ 100 000) — количество строк и столбцов в таблице соответственно.

Далее число k (1 ≤ k ≤ 100 000) — количество заданий учительницы, которые нужно выполнить Алёне.

Далее записана сама таблица, в которой a[i][j] (1 ≤ a[i][j] ≤ 10^9).

Далее даны k заданий, где l[i] и r[i] (1 ≤ l[i] ≤ r[i] ≤ n).

# Выходные данные
Для каждого i-ого из k заданий выведите "Yes", если в таблице, полученной из исходной оставлением строк с l[i] по r[i] включительно будет столбец, по которому она отсортирована по неубыванию, и "No" в противном случае.