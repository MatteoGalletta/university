
echo "Creating schema...";
mariadb < schema.sql
echo "Creating procedures...";
mariadb < procedures.sql
echo "Creating triggrrs...";
mariadb < triggers.sql
echo "Creating data...";
mariadb < data.sql
