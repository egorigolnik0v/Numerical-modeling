                                          Программа для моделирования физического маятника.

Класс State хранит массив параметров. Для данной системы это коородината(угол) и скорость. Можно моделировать другие системы, c другими уравнениями движения.
Класс Hoin отвечает за уравнение движения, метод его интегрирования.
Аналогом является класс Iler с несколько другой схемой интегрирования.
В файл вывода "Data.txt" записываютя скорость, координата, энергия для дальнейшей обработки.

В данном слчае задано уравнение движения x'' -k*x' +w*w*x + 2*sin(w2*t) = 0
То есть вынужденные колебания с наличием затухания. Меняя частоту вынуждающей силы, можно получить зависимость амплитуды установившихся колебаний от частоты вынуждающий силы - АЧХ.
По полученным данным можно построить графики.
