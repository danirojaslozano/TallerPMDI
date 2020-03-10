# ____________________________________________________________________________                                                                       
#     ____  __  _______  ____   __          __       ___   ____ ___   ____ 
#    / __ \/  |/  / __ \/  _/  / /   ____ _/ /_     |__ \ / __ \__ \ / __ \
#   / /_/ / /|_/ / / / // /   / /   / __ `/ __ \    __/ // / / /_/ // / / /
#  / ____/ /  / / /_/ // /   / /___/ /_/ / /_/ /   / __// /_/ / __// /_/ / 
# /_/   /_/  /_/_____/___/  /_____/\__,_/_.___/   /____/\____/____/\____/  
# ___________________________________________________________________________                                                                       
# randomForest.py
# Autor: Daniela Rojas
# Entrena un modelo de Machine Learnning de tipo Random Forest. Además realiza
# la validación y halla la matriz de confusión para así reconocer la precisión
# del modelo.
# ____________________________________________________________________________                                                                       
#

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.utils import shuffle

print('Cargando datos...')
separador=","
f = open("7posiciones.csv", "r")
datos = []
for x in f:
	datos.append(x.split(separador))

### Convierto los datos del .csv en un array de numpy y hallo la longitud de este
datosnp = np.array(datos)
longitud = datosnp.shape[0]
print('El archivo contiene ' + str(longitud) + ' mediciones')
### Constantes de numero de Colomna
COLUMNA_FECHA = 0
COLUMNA_PAQUETE = 1
COLUMNA_CLIENTE = 2
COLUMNA_X1 = 3
COLUMNA_X2 = 4
COLUMNA_X3 = 5
COLUMNA_X4 = 6
COLUMNA_X5 = 7
COLUMNA_X6 = 8
COLUMNA_LABEL = 9
feat_labels = [ "X1" , "X2", "X3" , "X4", "X5", "X6"]
Xstring = datosnp[:,COLUMNA_X1:COLUMNA_X6+1]
Ystring = datosnp[:,COLUMNA_LABEL]
X = []
fila = []
Y = []
### Como x tiene los datos en formato String recorro los vecotes para pasarlos a double.
for datos in Xstring:
	for dato in datos:
		fila.append(float(dato))
	X.append(fila)
	fila=[]
###### Como Y tiene los datos en formato String recorro los vecotes para pasarlos a entero.
for dato in Ystring:
	Y.append(int(dato))
#### Convertir listas X y Y a arreglos de numpy
X = np.array(X)
Y = np.array(Y)

#### Reorganizar aleatoreamente
X, Y = shuffle(X,Y)
#### Disvisión entre datos de entrenamiento y de prueba. 70, 30.
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.3, random_state=0)
print('Después de la divisón, se tienen ', X_train.shape[0], ' datos de entrenamiento y',  X_test.shape[0], ' datos de prueba')
print('La frecuencia de ocurrencia de cada una de las clases son:')
print(np.vstack((np.unique(Y_train), np.bincount(Y_train))).T)
#### Gráfica de la distribución de los datos de entrenamiento
sns.countplot(Y_train)
plt.show()


#################################################################################
#################################################################################
# Entrenar Modelo
#################################################################################
print('Entrenando modelo Random Forest ...')
model_rf = RandomForestClassifier(n_estimators=100, max_features=4, min_samples_leaf=10,random_state=0, n_jobs=2)
model_rf.fit(X_train, Y_train.ravel())
#####################################################
# Encontrar importancia de cada variable, y graficar
print('Calculando importancia de variables para prediccion ...')
importanciaVars=model_rf.feature_importances_
# Graficar con barras la importancia de cada variable
pos=[1, 2, 3, 4, 5, 6]
plt.rcdefaults()
fig, ax = plt.subplots()
ax.barh(pos, importanciaVars, align='center',color='blue')
ax.set_yticks(pos)
ax.set_yticklabels(feat_labels)
ax.invert_yaxis()  # labels read top-to-bottom
ax.set_xlabel('Importancia Variables')
plt.show()

#################################################################################
#################################################################################
# Validación
#################################################################################
######################################################
# Realizar prediccion en datos de validacion
print("""
      Prediccion en datos de validacion...""")
y_pred = model_rf.predict(X_test)
precision=accuracy_score(Y_test, y_pred)
print("%.4f" %precision)
# Matriz de confusion
print("""
      Graficar matriz de confusión...
      """)
tabla=pd.crosstab(Y_test.ravel(), y_pred, rownames=['Actual LOS'], colnames=['Predicted LOS'])
print(tabla*100/len(y_pred))



# ____________________________________________________________________________                                                                       
# ______            _      _        ______      _           
# |  _  \          (_)    | |       | ___ \    (_)          
# | | | |__ _ _ __  _  ___| | __ _  | |_/ /___  _  __ _ ___ 
# | | | / _` | '_ \| |/ _ \ |/ _` | |    // _ \| |/ _` / __|
# | |/ / (_| | | | | |  __/ | (_| | | |\ \ (_) | | (_| \__ \
# |___/ \__,_|_| |_|_|\___|_|\__,_| \_| \_\___/| |\__,_|___/
#                                             _/ |          
#                                            |__/           
# ____________________________________________________________________________                                                                       
#
#


