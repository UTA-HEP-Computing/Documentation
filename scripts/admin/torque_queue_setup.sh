echo supercomputer > /etc/torque/server_name
echo supercomputer > /var/spool/torque/server_priv/acl_svr/acl_hosts
echo root@supercomputer > /var/spool/torque/server_priv/acl_svr/operators
echo root@supercomputer > /var/spool/torque/server_priv/acl_svr/managers
echo "supercomputer np=48" > /var/spool/torque/server_priv/nodes
#echo "bigbird np=12" > /var/spool/torque/server_priv/nodes
echo "thingone np=12" > /var/spool/torque/server_priv/nodes
echo "thingtwo np=12" > /var/spool/torque/server_priv/nodes


echo supercomputer > /var/spool/torque/mom_priv/config

qmgr -c 'create queue cpu_queue'
qmgr -c 'set queue cpu_queue queue_type = Route'
qmgr -c 'set queue cpu_queue route_destinations = cpu_super'
#qmgr -c 'set queue cpu_queue route_destinations += cpu_bigbird'
qmgr -c 'set queue cpu_queue route_destinations += cpu_thingone'
qmgr -c 'set queue cpu_queue route_destinations += cpu_thingtwo'
qmgr -c 'set queue cpu_queue enabled = True'
qmgr -c 'set queue cpu_queue started = True'

qmgr -c 'create queue cpu_super'
qmgr -c 'set queue cpu_super queue_type = Execution'
qmgr -c 'set queue cpu_super resources_default.nodes = supercomputer'
qmgr -c 'set queue cpu_super resources_default.walltime = 12:00:00'
qmgr -c 'set queue cpu_super enabled = True'
qmgr -c 'set queue cpu_super started = True'
qmgr -c 'set queue cpu_super max_running = 48'

#qmgr -c 'create queue cpu_bigbird'
#qmgr -c 'set queue cpu_bigbird queue_type = Execution'
#qmgr -c 'set queue cpu_bigbird resources_default.nodes = bigbird'
#qmgr -c 'set queue cpu_bigbird resources_default.walltime = 12:00:00'
#qmgr -c 'set queue cpu_bigbird enabled = True'
#qmgr -c 'set queue cpu_bigbird started = True'
#qmgr -c 'set queue cpu_bigbird max_queuable = 1'
#qmgr -c 'set queue cpu_bigbird max_running = 12'

qmgr -c 'create queue cpu_thingone'
qmgr -c 'set queue cpu_thingone queue_type = Execution'
qmgr -c 'set queue cpu_thingone resources_default.nodes = thingone'
qmgr -c 'set queue cpu_thingone resources_default.walltime = 12:00:00'
qmgr -c 'set queue cpu_thingone enabled = True'
qmgr -c 'set queue cpu_thingone started = True'
qmgr -c 'set queue cpu_thingone max_running = 12'

qmgr -c 'create queue cpu_thingtwo'
qmgr -c 'set queue cpu_thingtwo queue_type = Execution'
qmgr -c 'set queue cpu_thingtwo resources_default.nodes = thingtwo'
qmgr -c 'set queue cpu_thingtwo resources_default.walltime = 12:00:00'
qmgr -c 'set queue cpu_thingtwo enabled = True'
qmgr -c 'set queue cpu_thingtwo started = True'
qmgr -c 'set queue cpu_thingtwo max_running = 12'

qmgr -c 'create queue gpu_queue'
qmgr -c 'set queue gpu_queue queue_type = Route'
qmgr -c 'set queue gpu_queue route_destinations = gpu1super'
qmgr -c 'set queue gpu_queue route_destinations += gpu2super'
qmgr -c 'set queue gpu_queue route_destinations += gpu3super'
#qmgr -c 'set queue gpu_queue route_destinations += gpu0bigbird'
#qmgr -c 'set queue gpu_queue route_destinations += gpu1bigbird'
#qmgr -c 'set queue gpu_queue route_destinations += gpu2bigbird'
#qmgr -c 'set queue gpu_queue route_destinations += gpu3bigbird'

qmgr -c 'set queue gpu_queue route_destinations += gpu0thingone'
qmgr -c 'set queue gpu_queue route_destinations += gpu1thingone'
qmgr -c 'set queue gpu_queue route_destinations += gpu2thingone'
qmgr -c 'set queue gpu_queue route_destinations += gpu3thingone'

qmgr -c 'set queue gpu_queue route_destinations += gpu0thingtwo'
qmgr -c 'set queue gpu_queue route_destinations += gpu1thingtwo'
qmgr -c 'set queue gpu_queue route_destinations += gpu2thingtwo'
qmgr -c 'set queue gpu_queue route_destinations += gpu3thingtwo'



qmgr -c 'set queue gpu_queue enabled = True'
qmgr -c 'set queue gpu_queue started = True'


qmgr -c 'create queue gpu_super'
qmgr -c 'set queue gpu_super queue_type = Route'
qmgr -c 'set queue gpu_super route_destinations = gpu0super'
qmgr -c 'set queue gpu_super route_destinations += gpu1super'
qmgr -c 'set queue gpu_super route_destinations += gpu2super'
qmgr -c 'set queue gpu_super route_destinations += gpu3super'
qmgr -c 'set queue gpu_super enabled = True'
qmgr -c 'set queue gpu_super started = True'

qmgr -c 'create queue gpu0super'
qmgr -c 'set queue gpu0super queue_type = Execution'
qmgr -c 'set queue gpu0super resources_default.nodes = supercomputer'
qmgr -c 'set queue gpu0super resources_default.walltime = 12:00:00'
qmgr -c 'set queue gpu0super enabled = True'
qmgr -c 'set queue gpu0super started = True'
qmgr -c 'set queue gpu0super max_running = 1'

qmgr -c 'create queue gpu1super'
qmgr -c 'set queue gpu1super queue_type = Execution'
qmgr -c 'set queue gpu1super resources_default.nodes = supercomputer'
qmgr -c 'set queue gpu1super resources_default.walltime = 12:00:00'
qmgr -c 'set queue gpu1super enabled = True'
qmgr -c 'set queue gpu1super started = True'
qmgr -c 'set queue gpu1super max_running = 1'

qmgr -c 'create queue gpu2super'
qmgr -c 'set queue gpu2super queue_type = Execution'
qmgr -c 'set queue gpu2super resources_default.nodes = supercomputer'
qmgr -c 'set queue gpu2super resources_default.walltime = 12:00:00'
qmgr -c 'set queue gpu2super enabled = True'
qmgr -c 'set queue gpu2super started = True'
qmgr -c 'set queue gpu2super max_running = 1'

qmgr -c 'create queue gpu3super'
qmgr -c 'set queue gpu3super queue_type = Execution'
qmgr -c 'set queue gpu3super resources_default.nodes = supercomputer'
qmgr -c 'set queue gpu3super resources_default.walltime = 12:00:00'
qmgr -c 'set queue gpu3super enabled = True'
qmgr -c 'set queue gpu3super started = True'
qmgr -c 'set queue gpu3super max_running = 1'


#qmgr -c 'create queue gpu_bigbird'
#qmgr -c 'set queue gpu_bigbird queue_type = Route'
#qmgr -c 'set queue gpu_bigbird route_destinations = gpu0bigbird'
#qmgr -c 'set queue gpu_bigbird route_destinations += gpu1bigbird'
#qmgr -c 'set queue gpu_bigbird route_destinations += gpu2bigbird'
#qmgr -c 'set queue gpu_bigbird route_destinations += gpu3bigbird'
#qmgr -c 'set queue gpu_bigbird enabled = True'
#qmgr -c 'set queue gpu_bigbird started = True'
#
#qmgr -c 'create queue gpu0bigbird'
#qmgr -c 'set queue gpu0bigbird queue_type = Execution'
#qmgr -c 'set queue gpu0bigbird resources_default.nodes = bigbird'
#qmgr -c 'set queue gpu0bigbird resources_default.walltime = 12:00:00'
#qmgr -c 'set queue gpu0bigbird enabled = True'
#qmgr -c 'set queue gpu0bigbird started = True'
#qmgr -c 'set queue gpu0bigbird max_running = 1'
#
#qmgr -c 'create queue gpu1bigbird'
#qmgr -c 'set queue gpu1bigbird queue_type = Execution'
#qmgr -c 'set queue gpu1bigbird resources_default.nodes = bigbird'
#qmgr -c 'set queue gpu1bigbird resources_default.walltime = 12:00:00'
#qmgr -c 'set queue gpu1bigbird enabled = True'
#qmgr -c 'set queue gpu1bigbird started = True'
#qmgr -c 'set queue gpu1bigbird max_running = 1'
#
#qmgr -c 'create queue gpu2bigbird'
#qmgr -c 'set queue gpu2bigbird queue_type = Execution'
#qmgr -c 'set queue gpu2bigbird resources_default.nodes = bigbird'
#qmgr -c 'set queue gpu2bigbird resources_default.walltime = 12:00:00'
#qmgr -c 'set queue gpu2bigbird enabled = True'
#qmgr -c 'set queue gpu2bigbird started = True'
#qmgr -c 'set queue gpu2bigbird max_running = 1'
#
#qmgr -c 'create queue gpu3bigbird'
#qmgr -c 'set queue gpu3bigbird queue_type = Execution'
#qmgr -c 'set queue gpu3bigbird resources_default.nodes = bigbird'
#qmgr -c 'set queue gpu3bigbird resources_default.walltime = 12:00:00'
#qmgr -c 'set queue gpu3bigbird enabled = True'
#qmgr -c 'set queue gpu3bigbird started = True'
#qmgr -c 'set queue gpu3bigbird max_running = 1'


#formerly bigbird:

qmgr -c 'create queue gpu_thingone'
qmgr -c 'set queue gpu_thingone queue_type = Route'
qmgr -c 'set queue gpu_thingone route_destinations = gpu0thingone'
qmgr -c 'set queue gpu_thingone route_destinations += gpu1thingone'
qmgr -c 'set queue gpu_thingone route_destinations += gpu2thingone'
qmgr -c 'set queue gpu_thingone route_destinations += gpu3thingone'
qmgr -c 'set queue gpu_thingone enabled = True'
qmgr -c 'set queue gpu_thingone started = True'

qmgr -c 'create queue gpu0thingone'
qmgr -c 'set queue gpu0thingone queue_type = Execution'
qmgr -c 'set queue gpu0thingone resources_default.nodes = thingone'
qmgr -c 'set queue gpu0thingone resources_default.walltime = 12:00:00'
qmgr -c 'set queue gpu0thingone enabled = True'
qmgr -c 'set queue gpu0thingone started = True'
qmgr -c 'set queue gpu0thingone max_running = 1'

qmgr -c 'create queue gpu1thingone'
qmgr -c 'set queue gpu1thingone queue_type = Execution'
qmgr -c 'set queue gpu1thingone resources_default.nodes = thingone'
qmgr -c 'set queue gpu1thingone resources_default.walltime = 12:00:00'
qmgr -c 'set queue gpu1thingone enabled = True'
qmgr -c 'set queue gpu1thingone started = True'
qmgr -c 'set queue gpu1thingone max_running = 1'

qmgr -c 'create queue gpu2thingone'
qmgr -c 'set queue gpu2thingone queue_type = Execution'
qmgr -c 'set queue gpu2thingone resources_default.nodes = thingone'
qmgr -c 'set queue gpu2thingone resources_default.walltime = 12:00:00'
qmgr -c 'set queue gpu2thingone enabled = True'
qmgr -c 'set queue gpu2thingone started = True'
qmgr -c 'set queue gpu2thingone max_running = 1'

qmgr -c 'create queue gpu3thingone'
qmgr -c 'set queue gpu3thingone queue_type = Execution'
qmgr -c 'set queue gpu3thingone resources_default.nodes = thingone'
qmgr -c 'set queue gpu3thingone resources_default.walltime = 12:00:00'
qmgr -c 'set queue gpu3thingone enabled = True'
qmgr -c 'set queue gpu3thingone started = True'
qmgr -c 'set queue gpu3thingone max_running = 1'




qmgr -c 'create queue gpu_thingtwo'
qmgr -c 'set queue gpu_thingtwo queue_type = Route'
qmgr -c 'set queue gpu_thingtwo route_destinations = gpu0thingtwo'
qmgr -c 'set queue gpu_thingtwo route_destinations += gpu1thingtwo'
qmgr -c 'set queue gpu_thingtwo route_destinations += gpu2thingtwo'
qmgr -c 'set queue gpu_thingtwo route_destinations += gpu3thingtwo'
qmgr -c 'set queue gpu_thingtwo enabled = True'
qmgr -c 'set queue gpu_thingtwo started = True'

qmgr -c 'create queue gpu0thingtwo'
qmgr -c 'set queue gpu0thingtwo queue_type = Execution'
qmgr -c 'set queue gpu0thingtwo resources_default.nodes = thingtwo'
qmgr -c 'set queue gpu0thingtwo resources_default.walltime = 12:00:00'
qmgr -c 'set queue gpu0thingtwo enabled = True'
qmgr -c 'set queue gpu0thingtwo started = True'
qmgr -c 'set queue gpu0thingtwo max_running = 1'

qmgr -c 'create queue gpu1thingtwo'
qmgr -c 'set queue gpu1thingtwo queue_type = Execution'
qmgr -c 'set queue gpu1thingtwo resources_default.nodes = thingtwo'
qmgr -c 'set queue gpu1thingtwo resources_default.walltime = 12:00:00'
qmgr -c 'set queue gpu1thingtwo enabled = True'
qmgr -c 'set queue gpu1thingtwo started = True'
qmgr -c 'set queue gpu1thingtwo max_running = 1'

qmgr -c 'create queue gpu2thingtwo'
qmgr -c 'set queue gpu2thingtwo queue_type = Execution'
qmgr -c 'set queue gpu2thingtwo resources_default.nodes = thingtwo'
qmgr -c 'set queue gpu2thingtwo resources_default.walltime = 12:00:00'
qmgr -c 'set queue gpu2thingtwo enabled = True'
qmgr -c 'set queue gpu2thingtwo started = True'
qmgr -c 'set queue gpu2thingtwo max_running = 1'

qmgr -c 'create queue gpu3thingtwo'
qmgr -c 'set queue gpu3thingtwo queue_type = Execution'
qmgr -c 'set queue gpu3thingtwo resources_default.nodes = thingtwo'
qmgr -c 'set queue gpu3thingtwo resources_default.walltime = 12:00:00'
qmgr -c 'set queue gpu3thingtwo enabled = True'
qmgr -c 'set queue gpu3thingtwo started = True'
qmgr -c 'set queue gpu3thingtwo max_running = 1'

qmgr -c 'set server scheduling = true'
qmgr -c 'set server keep_completed = 300'
qmgr -c 'set server mom_job_sync = true'

qmgr -c 'set server submit_hosts = supercomputer'
#qmgr -c 'set server submit_hosts += bigbird'
qmgr -c 'set server submit_hosts += thingone'
qmgr -c 'set server submit_hosts += thingtwo'


qmgr -c 'set server default_queue = gpu_queue'

qmgr -c 'set server allow_node_submit = true'
