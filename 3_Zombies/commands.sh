kill -9 <process_id> # SIGKILL
kill <process_id> # SIGTERM

ps aux | grep defunct # Посмотреть все процессы зомби

ps -xal | grep defunct # Поиск родителя (PPID в четвертом столбце)

