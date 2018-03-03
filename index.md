---
title: ''
---

О чем этот сайт?
----------------

Этот сайт о практических занятиях 05 группы (2016 года набора) по языку `С`, ассемблеру `nasm` и курсу операционных систем.
А именно о подгруппе [Смирнова Александра Владимировича](https://istina.msu.ru/profile/Sander/)(1-2 семестр) и [Герасимова Сергея Валерьевича](https://istina.msu.ru/profile/sergun/)(3-4 семестр).
Помимо задач с семинаров, здесь можно найти задачи из тестовых систем [unicorn.ejudge](https://unicorn.ejudge.ru) и [contest.solutions](http://contest.solutions) (aka [earth.ispras](http://earth.ispras.ru)).
Автор не гарантирует корректность содержания сайта, но честно обещает стараться её поддерживать.

Disclamer
---------

Текст задач распрастраняется в том виде в котором они были представлены мне. Все права принадлежат создателям.
Содержимое предназначено только для студентов проходящих обучение на системах unicorn.ejudge и contest.solutions.
Если вы не студент, однако желаете воспользоваться данными материалами, вам необходимо получить специальное разрешение [Чернова Александра Владимировича](https://istina.msu.ru/profile/chernovav/).

Table of Contents
-----------------

{% for file in site.pages %}{% if file.path contains '+' %}
 - [{{ file.title }}]({{ file.path | replace: '.md','' }}) {% endif %}{% endfor %}


{: style="text-align: center"}
{::comment}
vim: wrap linebreak
{:/comment}
