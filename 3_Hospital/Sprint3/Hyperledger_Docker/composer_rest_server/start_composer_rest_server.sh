#!/bin/bash
echo
echo "**********************************************"
echo "STARTING COMPOSER REST SERVER ...  "
echo "**********************************************"
echo

# alterar o nome do card pelo o seu card : admin@stagiop_tr_network

composer-rest-server -c admin@stagiop_tr_network -n always -w true

echo
echo "Browse Composer Rest Server at http://localhost:3000"
echo
