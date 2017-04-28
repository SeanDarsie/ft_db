/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_details.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:26:19 by sdarsie           #+#    #+#             */
/*   Updated: 2017/04/26 19:26:41 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void db_details(t_character *entry, char *path)
{
	char *tmp;
	char buff[30];
	time_t now;
	struct tm *sTm;

	now = time(0);
	sTm = gmtime(&now);
	strftime (buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", sTm);
	tmp = path;
	path = ft_strjoin(path, "/info.txt");
	free (tmp);
	FILE *info = fopen(path,"w");
	
	fprintf(info, "Record created at: %s\n\n", buff);
	fprintf(info, "Name: %s\n", entry->name);
	fprintf(info, "Class: %s\n", entry->class);
	fprintf(info, "Occupation: %s\n", entry->job);
	fprintf(info, "Title: %s\n", entry->title);

	fclose(info);
	printf("%s created\n", path);
}
