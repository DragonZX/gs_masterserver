Алгоритм работы:

1.	Запрос от клиента к мастерсерверу
2.	Ответ от мастерсервера клиенту
3.	Запрос от клиента к каждому серверу
Таким образом мастерсервер передает клиенту только список серверов и не следит за ними.

Запрос от клиента к мастерсерверу.

Пример запроса:

ffffffff6765747365727665727320362066756c6c20656d707479 (само сообщение без заголовков)

1.	ffffffff  - пустые байты
2.	остальное - текст сообщения - getservers 6 full empty

Запрос отправляется на cod4master.activision.com:20810.

Ответ от мастерсервера к клиенту.

Пример ответа:

fffffff67657473657276657273526573706f6e73650a005c050973f771205c454f46 (само сообщение без заголовка)

1.	fffffff - пустые байты
2.	67657473657276657273526573706f6e7365 - строка getserversResponse
3.	0a00 - перевод строки
4.	5c - разделитель, устанавливается между ip.
5.	сам ip:port, всего отводиться 6 байт на каждый ip. По одному байту на каждое значение и по 2 байта на порт. Пример 5.9.115.247:28960 - 050973f77120
6.	5c454f46 - символ окончания списка,передается в последнем сообщение. 
