#include <stdlib.h>
#include <string.h>

#include <jansson.h>

// What I would like to build
// {
//   "type": "FeatureCollection",
//   "features": [
//     {
//       "type": "Feature",
//       "properties": {},
//       "geometry": {
//         "type": "LineString",
//         "coordinates": [
//           [
//             27.6071834564209,
//             38.58359966761715
//           ],
//           [
//             27.608342170715332,
//             38.584807345233095
//           ],
//           [
//             27.608299255371094,
//             38.58953722034559
//           ],
//           [
//             27.604308128356934,
//             38.591650468096404
//           ],
//           [
//             27.613234519958496,
//             38.5771583773376
//           ]
//         ]
//       }
//     }
//   ]
// }
int main(int argc, char *argv[])
{
    double coordinates[10] = { 27.6071834564209,  38.58359966761715,
                             27.608342170715332,38.584807345233095,
                             27.608299255371094,38.58953722034559,
                             27.604308128356934,38.591650468096404,
                             27.613234519958496,38.5771583773376   };
    size_t i;
    char *text;

    json_t *root;
    json_error_t error;

    root = json_pack("{s:{s:s,s:{s:s,s:s}}}",
                    "DX57",
                    "destination", "400",
                    "function",
                    "value1", "123",
                    "value2", "123");

    text = json_dumps(root, JSON_INDENT(2));
    json_decref(root);
    puts(text);
    free(text);

    json_t *array = json_array();

    for (i = 0; i < 10; i++) {
            json_array_append_new(array, json_real(coordinates[i]));
            // Note: Since I use json_array_append_new(), no json_decref() is
            //       needed.
    }

    text = json_dumps(array, JSON_INDENT(2));
    json_decref(array);
    puts(text);
    free(text);

    return(0); 
}



