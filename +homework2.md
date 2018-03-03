Задания с семинаров по курсу систем программирования (4 семестр).
-----------------------------------------------------------------

| Номера заданий | Дата задания | Дата  сдачи |
|:--------------:|:------------:|:-----------:| {% for file in site.pages %}{% if file.path contains 'homework2/' %}
| [{{ file.path | replace: 'homework2/','' | replace: '.md','' }}]({{ file.path | replace: '.md','' }}) | {{ file.from }} | {{ file.until }} |{% endif %}{% endfor %}

