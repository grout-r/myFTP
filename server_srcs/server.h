/*
** server.h for ftp in /home/roman/Documents/dev/PSU_2014_myftp/server_srcs
** 
** Made by grout_r
** Login   <roman@epitech.net>
** 
** Started on  Thu Mar 19 13:29:44 2015 Roman
** Last update Thu Mar 19 13:56:23 2015 grout_r
*/

#ifndef _SERVER_H_
# define _SERVER_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <assert.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>

# define CMD_USER 0
# define CMD_LS 1
# define CMD_CD 2
# define CMD_GET 3
# define CMD_PUT 4
# define CMD_PWD 5
# define CMD_QUIT 6

# define DATA_PUT 7
# define DATA_LS 8
# define DATA_PWD 9

# define READY 10
# define ABORT 11

# define LAST_ONE 12

typedef struct		s_packet
{
  int			type;
  int			size;
  char			data[1024];
}			t_packet;

typedef struct s_server
{
  struct sockaddr_in s_in;
  int		     port;
  int		     socket_fd;
}		t_server;

int			init_server(int ac, char **av, t_server *server);
int			loop(t_server *server);
int			treat(int client_fd, t_packet packet);
int			put(int client_fd, t_packet packet);
int			get(int client_fd, t_packet packet);
int			ls(int client_fd, t_packet packet);
int			pwd(int client_fd, t_packet packet);
int			cd(int client_fd, t_packet packet);
int			user(int client_fd, t_packet packet);

typedef int		(*funcptr)(int client_fd, t_packet packet);

#endif /* !_SERVER_H_ */
