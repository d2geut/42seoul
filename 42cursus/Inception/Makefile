COMPOSE = ./srcs/docker-compose.yml

all :
	mkdir -p /home/hanryu/data
	mkdir -p /home/hanryu/data/mariadb
	mkdir -p /home/hanryu/data/wordpress
	docker-compose -f $(COMPOSE) up --build -d
clean :
	docker-compose -f $(COMPOSE) down
fclean :
	docker-compose -f $(COMPOSE) down --rmi all
	docker volume rm $$(docker volume ls -qf dangling=true)
	rm -rf /home/hanryu/data
re :
	make fclean
	make all

ps :
	docker-compose -f $(COMPOSE) ps

log :
	docker-compose -f $(COMPOSE) logs

.PHONY : all clean fclean re