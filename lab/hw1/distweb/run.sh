go run backend/nodes/node_1/node_1_server.go &
echo $! > n1.pid
go run backend/nodes/node_2/node_2_server.go &
echo $! > n2.pid
go run backend/nodes/node_3/node_3_server.go &
echo $! > n3.pid
go run backend/nodes/node_4/node_4_server.go &
echo $! > n4.pid
