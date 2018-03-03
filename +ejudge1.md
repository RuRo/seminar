Задачи с unicorn.ejudge (3 семестр).
------------------------------------

В данном разделе находятся тексты задач из контестов [ejudge](https://unicorn.ejudge.ru).
Условия задач загружаются на сайт в полуавтоматическом режиме, а значит вероятность глюков возрастает.
Если вы заметили ошибки в этом разделе, пожалуйста немедленно напишите об этом на [ruro.ruro@ya.ru](mailto:ruro.ruro@ya.ru).

| Номер задачи | Имя задачи |
|:------------:|:---------- | {% for file in site.pages %}{% if file.path contains 'ejudge1/' %}
| [{{ file.path | replace: 'ejudge1/','' | replace: '.md','' }}]({{ file.path | replace: '.md','' }}) | {{ file.title | replace: 'Задача ','' }} |{% endif %}{% endfor %}

