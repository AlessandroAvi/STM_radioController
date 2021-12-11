# STM_radio_controller
 
This project is a radio controller system used for controlling the drone that I built. The radio controller uses an STM32 MCU and it uses a NRF module for sending the data to the receiving NRF module. This radio controller is equipped with 2 joysticks, some buttons and switches.

# BOM

| **COMPONENT**           | **MODEL**                    | **N OF PIECES** | **COST €**| **LINK** |
| ----------------------- |:----------------------------:|:---------------:|:---------:| --------:|
| STM blackpill           | STM32 F411                   | 1               | 6.68      | [here](https://it.aliexpress.com/item/32792513237.html?spm=a2g0s.9042311.0.0.74a34c4dBViBGv)
| ST link                 | -                            | 1               | 3.45      | [here](https://it.aliexpress.com/item/32792513237.html?spm=a2g0s.9042311.0.0.74a34c4dBViBGv)
| NRF24 tx + antenna      | NRF24L01                     | 1               | 1.85      | [here](https://it.aliexpress.com/item/32272725011.html?spm=a2g0s.9042311.0.0.74a34c4dBViBGv)
| Display 480x320 - 3.2"  | TFT display screen ILI9486   | 1               | 9.92     | [here](https://it.aliexpress.com/item/4001247380483.html?spm=a2g0o.productlist.0.0.248279ebKSZWhT&algo_pvid=0093292f-33ab-4618-a51c-bde38f8fd506&algo_exp_id=0093292f-33ab-4618-a51c-bde38f8fd506-43&pdp_ext_f=%7B%22sku_id%22%3A%2210000015454172922%22%7D)
| Joystick                | arduino joystick analog      | 2               | 0.52x2    | [here](https://it.aliexpress.com/item/32263199828.html?spm=a2g0s.9042311.0.0.74a34c4dBViBGv)
| Battery holder          | for 3 batteries 18650        | 1               | 0.73      | [here](https://it.aliexpress.com/item/1005002410468384.html?spm=a2g0o.productlist.0.0.56313a21GUZq3K&algo_pvid=54f28b8d-b266-48cd-a70a-93b899a8bcd3&aem_p4p_detail=202112100021489728919746521060005601596&algo_exp_id=54f28b8d-b266-48cd-a70a-93b899a8bcd3-1&pdp_ext_f=%7B%22sku_id%22%3A%2212000020563128549%22%7D)
| Battery                 | 18650                        | 2               | 2x2       | [here](https://it.aliexpress.com/item/1005002325103098.html?spm=a2g0s.9042311.0.0.49664c4dRVHLxL)
| PCB for radio controller| DIY                          | 1               | -         | [no link]()

Total cost up to now: 27.67 €

# TO DO

- Include NRF module in the code
- Include joystick modules in the code
- Include display module in the code
- Creaet and buy a custom PCB