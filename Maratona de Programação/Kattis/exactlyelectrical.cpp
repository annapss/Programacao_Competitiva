//https://open.kattis.com/problems/exactlyelectrical
#include <iostream>
using namespace std;

int calculaDistancia(int coordAtualX, int coordAtualY, int coordX, int coordY)
{
    int dist = 0;
    if(coordAtualX < 0 && coordX < 0 || coordAtualX >= 0 && coordX >= 0)
        dist += abs(coordAtualX) - abs(coordX);
    else
        dist += abs(coordAtualX) + abs(coordX);
    
    if(coordAtualY < 0 && coordY < 0 || coordAtualY >= 0 && coordY >= 0)
        dist += abs(coordAtualY) - abs(coordY);
    else
        dist += abs(coordAtualY) + abs(coordY);
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    int coordOrigemX, coordOrigemY, coorDestX, coordDestY;
    int bateria, distOrigem, distDestino, coordAtualX, coordAtualY;
    cin >> coordOrigemX >> coordOrigemY;
    cin >> coorDestX >> coordDestY;
    cin >> bateria;
    coordAtualX = coordOrigemX;
    coordAtualY = coordOrigemY;
    do
    {
        distDestino = calculaDistancia(coordAtualX, coordAtualY, coorDestX, coordDestY);
        distOrigem = calculaDistancia(coordAtualX, coordAtualY, coordOrigemX, coordOrigemY);        
        if(distDestino + distOrigem == bateria)
        {
            cout << "Y\n";
            return 0;
        }
        else
        {
            coordAtualX++;
        }
    } while (distOrigem + distDestino <= bateria);
    cout << "N\n";
}