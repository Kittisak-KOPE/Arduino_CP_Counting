import time
from uuid import uuid4
import paho.mqtt.client as mqtt

broker_address = "127.0.0.1"

uuid = str(uuid4())

client = mqtt.Client(uuid)

client.connect(broker_address)

for iten in range(20):

    client.publish("car_park", uuid+',1')
    time.sleep(5)