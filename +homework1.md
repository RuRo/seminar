Задания с семинаров по курсу операционных систем (3 семестр).
-------------------------------------------------------------

| Номера заданий | Дата задания | Дата  сдачи |
|:--------------:|:------------:|:-----------:| {% for file in site.pages %}{% if file.path contains 'homework1/' %}
| [{{ file.path | replace: 'homework1/','' | replace: '.md','' }}]({{ file.path | replace: '.md','' }}) | {{ file.from }} | {{ file.until }} |{% endif %}{% endfor %}

