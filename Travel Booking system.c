#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NUM_CITIES 15
#define NUM_TRIPS 5
#define NUM_HOTELS 5
#define NUM_ACTIVITIES 5

const char *cities[NUM_CITIES] = {
        "Paris", "Dubai", "London", "Tokyo", "Rome",
        "Hong Kong", "Buenos Aires", "Canada", "New Orleans", "Florida Keys",
        "Oahu, Hawaii", "Las Vegas", "New York City", "Crete, Greece", "Barcelona"};

    const char *trips[NUM_CITIES][NUM_TRIPS] = {
        // Paris
        {"Plan 1: Budget = Rs.245,000 | 3 Days | Cultural Exploration",
         "Plan 2: Budget = Rs.130,000 | 5 Days | Iconic Landmarks & Museums",
         "Plan 3: Budget = Rs.200,000 | 7 Days | Luxury Art & History Immersion",
         "Plan 4: Budget = Rs.110,000 | 4 Days | Family Fun & Exploration",
         "Plan 5: Budget = Rs.90,000  | 5 Days | Off-the-Beaten-Path Paris"},
        // Dubai
        {"Plan 1: Budget = Rs.39,840  | 3 Days | Budget Exploration",
         "Plan 2: Budget = Rs.170,150 | 5 Days | Iconic Landmarks & Modern Marvels",
         "Plan 3: Budget = Rs.290,500 | 7 Days | Luxury Art, Culture & Indulgence",
         "Plan 4: Budget = Rs.192,560 | 4 Days | Family Fun & Adventure",
         "Plan 5: Budget = Rs.124,500 | 5 Days | Offbeat Dubai Experiences"},
        // London
        {"Plan 1: Budget = Rs.112,464 | 3 Days | Budget-Friendly London Exploration",
         "Plan 2: Budget = Rs.937,200 | 5 Days | Iconic London Landmarks & Museums",
         "Plan 3: Budget = Rs.570,000 | 7 Days | Family Fun & Exploration",
         "Plan 5: Budget = Rs.596,400 | 5 Days | Off-the-Beaten-Path London"},
        // Tokyo
        {"Plan 1: Budget = Rs.28,320  | 3 Days | Budget-Friendly Tokyo Exploration",
         "Plan 2: Budget = Rs.100,300 | 5 Days | Iconic Tokyo Landmarks & Culture",
         "Plan 3: Budget = Rs.206,500 | 7 Days | Luxury Tokyo Art, History & Gourmet",
         "Plan 4: Budget = Rs.118,000 | 4 Days | Family Fun & Entertainment",
         "Plan 5: Budget = Rs.79,650  | 5 Days | Unique & Local Tokyo Experiences"},
        // Rome
        {"Plan 1: Budget = Rs.42,885  | 3 Days | Budget-Friendly Roman Holiday",
         "Plan 2: Budget = Rs.142,950 | 5 Days | Iconic Ancient Rome & Vatican City",
         "Plan 3: Budget = Rs.342,550 | 7 Days | Luxury Roman Art, History & Cuisine",
         "Plan 4: Budget = Rs.100,000 | 4 Days | Family Fun & Exploration",
         "Plan 5: Budget = Rs.119,125 | 5 Days | Off-the-Beaten-Path Rome"},
        // Hong Kong
        {"Plan 1: Budget = Rs.40,000  | 3 Days | Cultural Flavours",
         "Plan 2: Budget = Rs.120,000 | 5 Days | Iconic Views & Island Escape",
         "Plan 3: Budget = Rs.180,000 | 7 Days | Luxury Heritage & Culinary Delights",
         "Plan 4: Budget = Rs.100,000 | 4 Days | Family Fun & City Exploration",
         "Plan 5: Budget = Rs.80,000  | 5 Days  | Off-the-Beaten-Path Hong Kong"},
        // Buenos Aires
        {"Plan 1: Budget = Rs.30,000  | 3 Days | Tango & Landmarks",
         "Plan 2: Budget = Rs.75,000  | 5 Days | Culture & Elegance",
         "Plan 3: Budget = Rs.130,000 | 7 Days | History, Art & Gaucho Life",
         "Plan 4: Budget = Rs.70,000  | 4 Days | Family Fun & Culture",
         "Plan 5: Budget = Rs.55,000  | 5 Days | Local Flavours & Hidden Gems"},
        // Canada
        {"Plan 1: Budget = Rs.60,000  | 5 Days | Toronto Taster",
         "Plan 2: Budget = Rs.80,000  | 5 Days| Montreal Charm",
         "Plan 3: Budget = Rs.150,000 | 7 Days | Vancouver & Whistler Adventure",
         "Plan 4: Budget = Rs.100,000 | 6 Days | Rockies Highlights (Calgary Focus)",
         "Plan 5: Budget = Rs.70,000  | 5 Days | Ottawa & Quebec City History"},
        // New Orleans
        {"Plan 1: Budget = Rs.30,000  | 3 Days | French Quarter & Music",
         "Plan 2: Budget = Rs.65,000  | 5 Days | History, Culture & Flavours",
         "Plan 3: Budget = Rs.110,000 | 7 Days | Luxury, Music & Culinary Delights",
         "Plan 4: Budget = Rs.60,000  | 4 Days | Family Fun & Exploration",
         "Plan 5: Budget = Rs.50,000  | 5 Days | Off-the-Beaten-Path New Orleans"},
        // Florida Keys
        {"Plan 1: Budget = Rs.45,000  | 3 Days | Key West Escape",
         "Plan 2: Budget = Rs.80,000  | 5 Days | Upper & Middle Keys Adventure",
         "Plan 3: Budget = Rs.140,000 | 7 Days | Luxury Keys Immersion",
         "Plan 4: Budget = Rs.70,000  | 4 Days | Family Fun in the Keys",
         "Plan 5: Budget = Rs.55,000  | 5 Days | Lower Keys Relaxation & Nature"},
        // Oahu, Hawaii
        {"Plan 1: Budget = Rs.70,000  | 3 Days | Waikiki & Pearl Harbor",
         "Plan 2: Budget = Rs.120,000 | 5 Days | Island Highlights",
         "Plan 3: Budget = Rs.200,000 | 7 Days | Luxury & Adventure",
         "Plan 4: Budget = Rs.100,000 | 5 Days | Family Fun on Oahu",
         "Plan 5: Budget = Rs.80,000  | 5 Days | North Shore & Island Exploration"},
        // Las Vegas
        {"Plan 1: Budget = Rs.30,000  | 3 Days | The Strip & Shows",
         "Plan 2: Budget = Rs.60,000  | 5 Days | Iconic Vegas & Day Trip",
         "Plan 3: Budget = Rs.150,000 | 7 Days | Luxury, Entertainment & Grand Canyon",
         "Plan 4: Budget = Rs.70,000  | 4 Days | Family Fun in Vegas",
         "Plan 5: Budget = Rs.50,000  | 5 Days | Off-the-Beaten-Path Vegas"},
        // New York City
        {"Plan 1: Budget = Rs.50,000  | 3 Days | Iconic Manhattan",
         "Plan 2: Budget = Rs.90,000  | 5 Days | Museums & Neighborhoods",
         "Plan 3: Budget = Rs.180,000 | 7 Days | Luxury Art & Culture Immersion",
         "Plan 4: Budget = Rs.80,000  | 4 Days | Family Fun in the Big Apple",
         "Plan 5: Budget = Rs.60,000  | 5 Days | Off-the-Beaten-Path NYC"},
        // Crete, Greece
        {"Plan 1: Budget = Rs.35,000  | 3 Days | Heraklion & Knossos",
         "Plan 2: Budget = Rs.65,000  | 5 Days | Chania & West Crete",
         "Plan 3: Budget = Rs.120,000 | 7 Days | East Crete Luxury & History",
         "Plan 4: Budget = Rs.70,000  | 5 Days | South Crete Adventure & Beaches",
         "Plan 5: Budget = Rs.55,000  | 5 Days | Rethymno Charm & Inland"},
        // Barcelona
        {"Plan 1: Budget = Rs.40,000  | 3 Days | Gaudí & Gothic",
         "Plan 2: Budget = Rs.75,000  | 5 Days | Art, Architecture & Beach",
         "Plan 3: Budget = Rs.140,000 | 7 Days | Luxury Gaudí & Catalan Culture",
         "Plan 4: Budget = Rs.70,000  | 4 Days | Family Fun in Barcelona",
         "Plan 5: Budget = Rs.55,000  | 5 Days | Local Life & Hidden Gems"}};

    const char *tripDetails[NUM_CITIES][NUM_TRIPS] = {
        // Paris
        {
            // Plan 1
            "Hotel: 10ᵉ/11ᵉ/18ᵉ arrondissement\n"
            "| Day | Activities                                                                                                                             \n"
            "| --- | -------------------------------------------------------------------------------------------------------------------------------------- \n"
            "| 1   | - Self-guided walking tour of Île de la Cité: exterior of Notre-Dame (restoration ongoing)                                             \n"
            "        - Visit Sainte-Chapelle                                                                                                                \n"
            "        - Wander the Latin Quarter's cafés & bookshops                                                                                         \n"
            "| 2   | - Morning at Musée d'Orsay (Impressionist masterpieces)                                                                                \n"
            "        - Afternoon stroll & relaxation in Jardin du Luxembourg                                                                                \n"
            "| 3   | - Free morning to explore local markets or arrondissements                                                                             \n"
            "        - Evening: sunset walk along the Seine & Eiffel Tower illumination",

            // Plan 2
            "Hotel: Le Marais, Saint-Germain-des-Prés, or the Latin Quarter\n"
            "| Day | Activities                                                                                          \n"
            "| --- | --------------------------------------------------------------------------------------------------- \n"
            "| 1   | - Ascend Eiffel Tower (2nd level; pre-book ticket)                                                  \n"
            "        - Leisurely picnic in the Champ-de-Mars                                                             \n"
            "| 2   | - Morning at the Louvre: Mona Lisa, Venus de Milo (guided)                                          \n"
            "| 3   | - Day trip to Palace of Versailles: château, Hall of Mirrors & gardens                              \n"
            "| 4   | - Trocadéro gardens for tower views,Seine River cruise (evening option)                             \n"
            "| 5   | - Montmartre: Sacre-Cœur & Place du Tertre stroll                                                  ",

            // Plan 3
            "Hotel: Luxury hotel near Champs-Elysées or Saint-Germain\n"
            "| Day | Activities                                                                                                                        \n"
            "| --- | --------------------------------------------------------------------------------------------------------------------------------- \n"
            "| 1   | - Private Louvre tour (tailored interests)                                                                                        \n"
            "| 2   | - Private Musée d'Orsay guided visit (Impressionism focus)                                                                        \n"
            "| 3   | - Sainte Chapelle & Conciergerie private visit                                                                                    \n"
            "| 4   | - Le Marais: Place des Vosges & Picasso Museum (skip line tickets)                                                                \n"
            "| 5   | - Opéra Garnier behind the scenes tour                                                                                            \n"
            "| 6   | - Giverny day trip: Monet's house & gardens                                                                                       \n"
            "| 7   | - Gourmet food tour & evening Seine dinner cruise                                                                            ",

            // Plan 4
            "Hotel: Family-friendly hotel/apartment (near Disneyland)\n"
            "| Day | Activities                                                                                                              \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------------  \n"
            "| 1   | - Kids' discovery Eiffel Towern                                                                                         \n"
            "        - Picnic on Champs de Mars                                                                                              \n"
            "| 2   | - Hop on Batobus & Jardin du Luxembourg playground                                                                      \n"
            "| 3   | - Aquarium de Paris interactive exhibits                                                                                \n"
            "| 4   | - Disneyland Paris full day (skip lines)                                                                              ",

            // Plan 5
            "Hotel: Boutique guesthouse in Belleville or Canal Saint-Martin\n"
            "| Day | Activities                                                                                                                             \n"
            "| --- | -------------------------------------------------------------------------------------------------------------------------------------- \n"
            "| 1   | - Pre Lachaise Cemetery (Morrison & Wilde graves)                                                                                     \n"
            "| 2   | - Canal Saint-Martin café hop & boat tour                                                                                              \n"
            "| 3   | - Catacombs of Paris (booking required)                                                                                                \n"
            "| 4   | - Promenade Plantée & Belleville street art tour                                                                                       \n"
            "| 5   | - Musée Rodin galleries & sculpture garden                                                                                 "},

        // Dubai
        {
            // Plan 1
            "Hotel: Deira or Bur Dubai\n"
            "| Day | Activities                                                                                                                 \n"
            "| --- | -------------------------------------------------------------------------------------------------------------------------- \n"
            "| 1   | - Explore Al Fahidi District (Bastakiya)                                                                                   \n"
            "        - Abra ride across Dubai Creek                                                                                             \n"
            "        - Spice Souk & Gold Souk                                                                                                   \n"
            "| 2   | - Dubai Frame panoramic views                                                                                              \n"
            "        - Zabeel Park                                                                                                              \n"
            "        - Dubai Fountain show at Dubai Mall                                                                                        \n"
            "| 3   | - Discover Jumeirah Mosque                                                                                                 \n"
            "        - Relax at Jumeirah Beach                                                                                                  \n"
            "        - Evening local eateries in Deira/Bur Dubai                     ",

            // Plan 2
            "Hotel: Sheikh Zayed Road or Dubai Marina\n"
            "| Day | Activities                                                                                      \n"
            "| --- | ----------------------------------------------------------------------------------------------  \n"
            "| 1   | - Ascend Burj Khalifa (pre-book ticket)                                                         \n"
            "        -  Visit The Dubai Mall\n"
            "        - Watch the Fountain show                                                                       \n"
            "| 2   | - Miracle Garden (seasonal)                                                                     \n"
            "        - Dubai Garden Glow (seasonal)                                                                  \n"
            "| 3   | - Desert safari with dune bashing & cultural experience                                         \n"
            "| 4   | - Dhow cruise on Dubai Marina                                                                   \n"
            "        - Stroll JBR & The Walk                                                                         \n"
            "| 5   | - Palm Jumeirah & The Pointe visit\n"
            "        - Optional ride on the Palm Monorail           ",

            // Plan 3
            "Hotel: Downtown Dubai or Palm Jumeirah\n"
            "| Day | Activities                                                         \n"
            "| --- | -----------------------------------------------------------------  \n"
            "| 1   | - Private VIP tour of Downtown Dubai & Burj Khalifa                \n"
            "| 2   | - Gallery hopping in Alserkal Avenue & Jameel Arts Centre          \n"
            "| 3   | - Explore Al Shindagha Historic District & Sheikh Saeed's House    \n"
            "| 4   | - Luxury desert retreat with private dining                        \n"
            "| 5   | - Relax at a high-end beach club on Palm Jumeirah                  \n"
            "| 6   | - Evening performance or tour at Dubai Opera                       \n"
            "| 7   | - Spa treatment & fine-dining with skyline views                  ",

            // Plan 4
            "Hotel: Near IMG Worlds or JBR\n"
            "| Day | Activities                                                           \n"
            "| --- | -------------------------------------------------------------------- \n"
            "| 1   | - Thrills at IMG Worlds of Adventure                                 \n"
            "| 2   | - Dubai Parks & Resorts day (Motiongate, Bollywood Parks, Legoland)  \n"
            "| 3   | - Aquaventure Waterpark or Wild Wadi                                 \n"
            "| 4   | - Dubai Aquarium & Underwater Zoo\n"
            "        - KidZania at Dubai Mall       ",

            // Plan 5
            "Hotel: Al Satwa or near Dubai Water Canal\n"
            "| Day | Activities                                                           \n"
            "| --- | -------------------------------------------------------------------  \n"
            "| 1   | - Street-art tour in Al Satwa                                        \n"
            "        - Textile Souk shopping                                              \n"
            "| 2   | - Bike/boat along Dubai Water Canal                                  \n"
            "        - Picnic in Safa Park                                                \n"
            "| 3   | - Coffee Museum visit                                                \n"
            "        - Theatre of Digital Art (ToDA)                                      \n"
            "| 4   | - Night abra ride on Dubai Creek                                     \n"
            "        - Explore seasonal night markets                                     \n"
            "| 5   | - Photo stop at Jumeirah Lakes Towers (JLT)                          \n"
            "        - Zip-line XLine Dubai Marina optional "},

        // London
        {
            // Plan 1
            "Hotel: Zone 2-3\n"
            "| Day | Activities                                                                                                                           \n"
            "| --- | ------------------------------------------------------------------------------------------------------------------------------------ \n"
            "| 1   | - Self-guided walking tour: Houses of Parliament, Big Ben (exterior)                                                                 \n"
            "        - Westminster Abbey                                                                                                                  \n"
            "        - Stroll through St. James's Park                                                                                                    \n"
            "| 2   | - British Museum (free entry main collection)                                                                                        \n"
            "        - Wander Covent Garden (street performers)                                                                                           \n"
            "        - Evening: free historic walking tour                                                                                                \n"
            "| 3   | - Borough Market (food stalls)                                                                                                       \n"
            "        - Walk along the South Bank                                                                                                          \n"
            "        - Evening: traditional pub atmosphere",

            // Plan 2
            "Hotel: Zone 1-2\n"
            "| Day | Activities                                                                                                                       \n"
            "| --- | -------------------------------------------------------------------------------------------------------------------------------  \n"
            "| 1   | - Tower of London (pre-book tickets)                                                                                             \n"
            "      - Walk across Tower Bridge                                                                                                         \n"
            "      - Explore The Shard Quarter (exterior)                                                                                             \n"
            "| 2   | - British Museum (key exhibits)                                                                                                  \n"
            "      - Afternoon in vibrant Soho                                                                                                        \n"
            "      - West End theatre performance (budget permitting)                                                                                 \n"
            "| 3   | - Buckingham Palace (exterior & Changing of the Guard)                                                                           \n"
            "      - Hyde Park & Kensington Gardens                                                                                                   \n"
            "      - Optional Kensington Palace tour                                                                                                  \n"
            "| 4   | - London Eye (pre-book tickets)                                                                                                  \n"
            "      - South Bank cultural area: Tate Modern (free entry)                                                                               \n"
            "| 5   | - Day trip to Greenwich: Royal Observatory & National Maritime Museum ",

            // Plan 3
            "Hotel: Luxury hotel in Mayfair or Kensington\n"
            "| Day | Activities                                                                                                            \n"
            "| --- | --------------------------------------------------------------------------------------------------------------------  \n"
            "| 1   | - Private guided tour of the National Gallery or Tate Britain                                                         \n"
            "| 2   | - Private guided Tower of London tour with early access                                                               \n"
            "| 3   | - Churchill War Rooms                                                                                                 \n"
            "        - Imperial War Museum                                                                                                 \n"
            "         - Evening fine dining                                                                                                \n"
            "| 4   | - Day trip to Windsor Castle (private guide option)                                                                   \n"
            "| 5   | - Victoria & Albert Museum (focused tour)                                                                             \n"
            "        - Afternoon tea at a luxury hotel                                                                                     \n"
            "        - Evening at the Royal Opera House                                                                                    \n"
            "| 6   | - Wallace Collection visit                                                                                            \n"
            "        - Shopping in Mayfair or Knightsbridge                                                                                \n"
            "| 7   | - Sir John Soane's Museum                                                                                             \n"
            "        - Evening: luxury Thames river dinner cruise              ",

            // Plan 4
            "Hotel: Family-friendly hotel/apartment in central London\n"
            "| Day | Activities                                                                       \n"
            "| --- | -------------------------------------------------------------------------------  \n"
            "| 1   | - London Zoo                                                                     \n"
            "        - Playground in Regent's Park                                                    \n"
            "| 2   | - London Eye ride                                                                \n"
            "        - SEA LIFE London Aquarium                                                       \n"
            "| 3   | - Science Museum (interactive exhibits)                                          \n"
            "        - Natural History Museum (dinosaurs)                                             \n"
            "| 4   | - Double-decker bus tour                                                         \n"
            "        - Hamleys toy store on Regent Street                ",

            // Plan 5
            "Hotel: Boutique guesthouse in Notting Hill or Shoreditch\n"
            "| Day | Activities                                                                       \n"
            "| --- | -------------------------------------------------------------------------------  \n"
            "| 1   | - Portobello Road Market in Notting Hill (Saturday)                              \n"
            "        - Electric Cinema visit                                                          \n"
            "| 2   | - Shoreditch street art tour                                                     \n"
            "        - Brick Lane Market (check schedule)                                             \n"
            "| 3   | - Camden Town shops & cafés                                                      \n"
            "        - Regent's Canal walk                                                            \n"
            "| 4   | - Dennis Severs' House in Spitalfields                                           \n"
            "        - Columbia Road Flower Market (Sunday)                                           \n"
            "| 5   | - Crystal Palace Park (dinosaurs & maze)                                         \n"
            "        - Dulwich Picture Gallery            "},

        // Toky
        {
            // Plan 1
            "Hotel: Ueno or Asakusa\n"
            "| Day | Activities                                                                                                                                \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------------------------------- \n"
            "| 1   | - Senso-ji Temple & Nakamise-dōri market (Asakusa)                              \n"
            "        - Ueno Park (free museums; zoo extra fee)                                       \n"
            "        - Ameya Yokocho market for budget eats                                          \n"
            "| 2   | - Meiji Jingu Shrine                                                            \n"
            "        - Harajuku: Takeshita Street & Omotesandō                                       \n"
            "        - Tokyo Metropolitan Government Building (free views)                           \n"
            "| 3   | - Imperial Palace East Garden                                                   \n"
            "        - Akihabara electronics district                                                \n"
            "        - Budget-friendly dinner in Akihabara                           ",

            // Plan 2
            "Hotel: Shinjuku or Shibuya\n"
            "| Day | Activities                                                                              \n"
            "| --- | --------------------------------------------------------------------------------------  \n"
            "| 1   | - Tokyo Skytree (pre-book tickets)                                                      \n"
            "        - Solamachi complex                                                                     \n"
            "| 2   | - Shibuya Crossing                                                                      \n"
            "        - Shops and cafés in Shibuya                                                            \n"
            "        - Dinner with city views                                                                \n"
            "| 3   | - Day trip to Hakone: Lake Ashi cruise, Mount Fuji views, art museums                   \n"
            "| 4   | - Ghibli Museum (advance tickets) or Edo-Tokyo Museum                                   \n"
            "        - Traditional Yanaka district                                                           \n"
            "| 5   | - Tsukiji Outer Market                                                                  \n"
            "        - Ginza shopping district                                                               \n"
            "        - Themed restaurant experience   ",

            // Plan 3
            "Hotel: Ginza or Marunouchi\n"
            "| Day | Activities                                                                                            \n"
            "| --- | ------------------------------------------------------------------------------------------------------\n"
            "| 1   | - Private tour of Nezu Museum (art & gardens)                  \n"
            "        - Browse Ginza boutiques                                       \n"
            "        - Michelin-starred dinner                                      \n"
            "| 2   | - Private Tokyo National Museum tour                           \n"
            "        - Traditional tea ceremony                                     \n"
            "| 3   | - Day trip to Kamakura: Great Buddha & temples                 \n"
            "| 4   | - Roppongi galleries: Mori Art Museum                          \n"
            "        - Tokyo City View observation deck                             \n"
            "        - Evening cocktails                                            \n"
            "| 5   | - High-end sushi at Tsukiji/Ginza                              \n"
            "        - Kabuki-za Theatre performance (optional)                     \n"
            "| 6   | - Kiyosumi Teien Garden                                        \n"
            "        - Museum of Contemporary Art Tokyo (MOT)                       \n"
            "        - Kaiseki multi-course meal                                    \n"
            "| 7   | - Shinjuku Gyoen National Garden                               \n"
            "        - Farewell dinner with city views                               ",

            // Plan 4
            "Hotel: Near major train stations\n"
            "| Day | Activities                                                                                   \n"
            "| --- | -------------------------------------------------------------------------------------------- \n"
            "| 1   | - Tokyo Disneyland or DisneySea                                                              \n"
            "| 2   | - Sanrio Puroland (Hello Kitty theme park)                                                   \n"
            "| 3   | - Ueno Zoo                                                                                   \n"
            "        - National Museum of Nature and Science                                                      \n"
            "| 4   | - teamLab Borderless or teamLab Planets digital art museum                                   \n"
            "        - Arcades & shops in Akihabara        ",

            // Plan 5
            "Hotel: Shimokitazawa or Koenji\n"
            "| Day | Activities                                                                       \n"
            "| --- | -------------------------------------------------------------------------------  \n"
            "| 1   | - Shimokitazawa vintage shops & quirky cafés                                     \n"
            "        - Live music at local venue                                                      \n"
            "| 2   | - Koenji counterculture shops                                                    \n"
            "        - Shotengai (local shopping street)                                              \n"
            "| 3   | - Japanese home-cooking class                                                    \n"
            "        - Nakano Broadway (anime & manga collectibles)                                   \n"
            "| 4   | - Gotokuji Temple (maneki-neko statues)                                          \n"
            "        - Setagaya Park                                                                  \n"
            "| 5   | - Cycle through neighborhoods                                                    \n"
            "        - Traditional sentō (public bathhouse)          "},

        // Hong Kong
        {
            // Plan 1
            "Hotel: Mong Kok or Yau Ma Tei\n"
            "| Day | Activities                                                                                                             \n"
            "| --- | ---------------------------------------------------------------------------------------------------------------------- \n"
            "| 1   | - Explore Mong Kok markets & Temple St Night Market                                                                    \n"
            "        - Wander Kowloon Park                                                                                                  \n"
            "| 2   | - Star Ferry across Victoria Harbour                                                                                   \n"
            "        - Explore Central & Sheung Wan (Man Mo Temple)                                                                         \n"
            "        - Sample local snacks & street food                                                                                    \n"
            "| 3   | - Visit Wong Tai Sin Temple                                                                                            \n"
            "        - Optional hike up Lion Rock Trail                                                                               ",

            // Plan 2
            "Hotel: Hong Kong Island\n"
            "| Day | Activities                                                                                                              \n"
            "| --- | -----------------------------------------------------------------------------------------------------------------       \n"
            "| 1   | - Ascend Victoria Peak via Peak Tram                                                                                    \n"
            "        - Peak Circle Walk                                                                                                      \n"
            "| 2   | - Hong Kong Museum of History                                                                                           \n"
            "        - Tsim Sha Tsui Promenade & Avenue of Stars                                                                             \n"
            "        - Symphony of Lights show                                                                                               \n"
            "| 3   | - Lantau Island: Big Buddha & Po Lin Monastery                                                                          \n"
            "        - Ngong Ping 360 cable car                                                                                              \n"
            "| 4   | - Explore SoHo district                                                                                                 \n"
            "        - Ride the Mid-Levels Escalator                                                                                         \n"
            "        - (Optional) Hong Kong Zoological & Botanical Gardens                                                                   \n"
            "| 5   | - Ferry to outlying island (Cheung Chau or Lamma)                                                                       \n"
            "        - Waterfront seafood lunch                                                                                       ",

            // Plan 3
            "Hotel: Luxury hotel in Central or Kowloon\n"
            "| Day | Activities                                                                                                  \n"
            "| --- | ----------------------------------------------------------------------------------------------------------- \n"
            "| 1   | - Private historical walking tour                                                                           \n"
            "        - Afternoon tea at a heritage hotel                                                                         \n"
            "| 2   | - Hollywood Road art & antique galleries                                                                    \n"
            "        - PMQ creative arts hub                                                                                     \n"
            "        - Fine dining experience                                                                                    \n"
            "| 3   | - Private junk boat cruise with gourmet lunch                                                               \n"
            "| 4   | - Hong Kong Museum of Art                                                                                   \n"
            "        - West Kowloon Cultural District (M+ Museum)                                                                \n"
            "        - Evening cultural performance                                                                              \n"
            "| 5   | - Day trip to Stanley & Repulse Bay                                                                         \n"
            "| 6   | - Michelin-star & local food tour                                                                           \n"
            "        - Cooking class with a local chef                                                                           \n"
            "| 7   | - Hong Kong Heritage Museum                                                                                 \n"
            "        - Chi Lin Nunnery & Nan Lian Garden                                                                         \n"
            "        - Farewell high tea                                                                                       ",

            // Plan 4
            "Hotel: Family-friendly hotel in Kowloon\n"
            "| Day | Activities                                                                                    \n"
            "| --- | --------------------------------------------------------------------------------------------  \n"
            "| 1   | - Victoria Peak & Madame Tussauds                                                             \n"
            "        - Picnic at Hong Kong Park                                                                    \n"
            "| 2   | - Full day at Hong Kong Disneyland                                                            \n"
            "| 3   | - Hong Kong Science Museum or Space Museum                                                    \n"
            "        - Star Ferry ride                                                                             \n"
            "        - Symphony of Lights show                                                                     \n"
            "| 4   | - Ocean Park Hong Kong (marine life & rides)                                                 ",

            // Plan 5
            "Hotel: Boutique guesthouse in Sham Shui Po\n"
            "| Day | Activities                                                                                       \n"
            "| --- | -----------------------------------------------------------------------------------------------  \n"
            "| 1   | - Explore Sham Shui Po markets & eateries                                                        \n"
            "        - Lei Cheng Uk Han Tomb site                                                                     \n"
            "| 2   | - Hike Dragon's Back Trail                                                                       \n"
            "        - Relax on Shek O Beach                                                                          \n"
            "| 3   | - Visit a New Territories walled village                                                         \n"
            "        - Hong Kong Wetland Park                                                                         \n"
            "| 4   | - Street-art hunt in Sheung Wan & Sai Ying Pun                                                   \n"
            "        - Dr. Sun Yat-sen Museum                                                                         \n"
            "        - Local café stop                                                                                \n"
            "| 5   | - Ferry to Peng Chau Island                                                                      \n"
            "        - Waterfront seafood lunch                                                                   ",
        },

        // Buenos Aires 
        {
            // Plan 1
            "Hotel: San Telmo or Monserrat\n"
            "| Day | Activities                                                                                             \n"
            "| --- | ------------------------------------------------------------------------------------------------------ \n"
            "| 1   | - Explore Plaza de Mayo & Casa Rosada (outside)                                                        \n"
            "        - Visit Catedral Metropolitana                                                                         \n"
            "        - Stroll Calle Defensa in San Telmo                                                                    \n"
            "| 2   | - La Boca neighborhood: Caminito Street art & tango dancers                                            \n"
            "        - Boca Juniors Stadium (optional museum)                                                               \n"
            "| 3   | - Walk Puerto Madero Eco-Reserve                                                                       \n"
            "        - Enjoy parrilla dinner in San Telmo or Palermo                      ",

            // Plan 2
            "Hotel: Recoleta or Palermo\n"
            "| Day | Activities                                                                                             \n"
            "| --- | ------------------------------------------------------------------------------------------------------ \n"
            "| 1   | - Visit Recoleta Cemetery & Evita's tomb                                                               \n"
            "        - Recoleta Cultural Center                                                                             \n"
            "| 2   | - MALBA (Latin American modern art museum)                                                             \n"
            "        - Palermo Soho cafes & boutiques                                                                       \n"
            "| 3   | - Guided tour of Teatro Colón                                                                          \n"
            "        - Tango show in the evening                                                                            \n"
            "| 4   | - Parks of Palermo: Rose Garden Walk & Japanese Garden                                                 \n"
            "| 5   | - San Telmo antiques market (Sunday) or guided bike tour                                               ",

            // Plan 3
            "Hotel: Luxury hotel near Recoleta or Puerto Madero\n"
            "| Day | Activities                                                                                             \n"
            "| --- | ------------------------------------------------------------------------------------------------------ \n"
            "| 1   | - Private architecture tour (Belle Époque & Art Nouveau highlights)                                    \n"
            "| 2   | - Guided tour of Museo Nacional de Bellas Artes                                                        \n"
            "| 3   | - Day trip to Tigre Delta with private boat ride                                                       \n"
            "| 4   | - Fine dining experience with wine pairing                                                             \n"
            "| 5   | - Cultural evening at Teatro Colón or Usina del Arte                                                   \n"
            "| 6   | - Cooking class: empanadas & asado techniques                                                          \n"
            "| 7   | - Visit Fundación PROA contemporary art center in La Boca                                              ",

            // Plan 4
            "Hotel: Family-friendly apartment in Palermo or Retiro\n"
            "| Day | Activities                                                                                             \n"
            "| --- | ------------------------------------------------------------------------------------------------------ \n"
            "| 1   | - Buenos Aires Eco Park (zoo & playgrounds)                                                            \n"
            "        - Botanical Gardens walk                                                                               \n"
            "| 2   | - Museo Participativo de Ciencias (hands-on science museum)                                            \n"
            "        - Puppet show or kids' tango lesson                                                                    \n"
            "| 3   | - Parque de la Costa theme park in Tigre                                                               \n"
            "| 4   | - Day trip to Estancia (ranch): horse rides & folk dancing                                             ",

            // Plan 5
            "Hotel: Boutique guesthouse in Colegiales or Chacarita\n"
            "| Day | Activities                                                                                             \n"
            "| --- | ------------------------------------------------------------------------------------------------------ \n"
            "| 1   | - Explore Chacarita Cemetery                                                                           \n"
            "        - Graffiti tour in Colegiales                                                                          \n"
            "| 2   | - Mataderos Fair (weekends): crafts, folk music & gaucho shows                                         \n"
            "| 3   | - Underground café hopping & live music night                                                          \n"
            "| 4   | - Browse vinyl & bookstores in Palermo Hollywood                                                       \n"
            "| 5   | - Sunset walk through Parque Centenario & street art spotting                                          "},

        // Canada 
        {
            // Plan 1
            "Hotel: Downtown Toronto\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Ascend the CN Tower                                                                                              \n"
            "        - Explore Harbourfront Centre                                                                                      \n"
            "| 2   | - Visit the Royal Ontario Museum (ROM)                                                                             \n"
            "        - Wander through Kensington Market                                                                                 \n"
            "| 3   | - Day trip to Niagara Falls                                                                                        \n"
            "        - Hornblower Niagara Cruises                                                                                       \n"
            "| 4   | - Explore St. Lawrence Market                                                                                      \n"
            "        - Visit the Distillery Historic District                                                                           \n"
            "| 5   | - Explore the Art Gallery of Ontario (AGO)                                                                         \n"
            "        - Stroll Queen Street West                                      ",

            // Plan 2
            "Hotel: Old Montreal or Downtown Montreal\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Explore Old Montreal                                                                                             \n"
            "        - Visit Notre-Dame Basilica                                                                                        \n"
            "| 2   | - Montreal Museum of Fine Arts (MMFA)                                                                              \n"
            "        - Wander the Underground City (RESO)                                                                               \n"
            "| 3   | - Visit Mount Royal Park                                                                                           \n"
            "        - Explore Plateau Mont-Royal                                                                                       \n"
            "| 4   | - Jean-Talon Market                                                                                                \n"
            "        - Discover Mile End                                                                                                \n"
            "| 5   | - Pointe-à-Callière archaeology museum                                                                             \n"
            "        - (Optional) Cirque du Soleil show                                  ",

            // Plan 3
            "Hotel: Downtown Vancouver (Days 1-4), Whistler Village (Days 4-6), Near Vancouver Airport (Day 6-7)\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Explore Stanley Park                                                                                             \n"
            "        - Vancouver Aquarium                                                                                               \n"
            "| 2   | - Granville Island Public Market                                                                                   \n"
            "        - Gastown                                                                                                          \n"
            "        - Vancouver Lookout                                                                                                \n"
            "| 3   | - Cross Capilano Suspension Bridge                                                                                 \n"
            "        - Grouse Mountain                                                                                                  \n"
            "| 4   | - Scenic drive to Whistler Village                                                                                 \n"
            "        - Peak 2Peak Gondola                                                                                               \n"
            "| 5   | - Hiking or biking in Whistler                                                                                     \n"
            "        - (Optional) Ziplining                                                                                             \n"
            "| 6   | - Explore Richmond area                                                                                            \n"
            "        - UBC Museum of Anthropology                                                                                       \n"
            "| 7   | - Depart from Vancouver                                                                                        ",

            // Plan 4
            "Hotel: Downtown Calgary (Days 1-3), Banff (Days 3-5), Near Calgary Airport (Days 5-6)                                      \n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Explore Downtown Calgary                                                                                         \n"
            "        - Heritage Park Historical Village                                                                                 \n"
            "| 2   | - Glenbow Museum                                                                                                   \n"
            "        - Wander Inglewood district                                                                                        \n"
            "| 3   | - Drive to Banff                                                                                                   \n"
            "        - Ride the Banff Gondola                                                                                           \n"
            "| 4   | - Drive the Bow Valley Parkway                                                                                     \n"
            "        - Visit Lake Louise                                                                                                \n"
            "| 5   | - Explore Moraine Lake & Johnston Canyon                                                                           \n"
            "| 6   | - Calgary Zoo\n"
            "        - Depart from Calgary                                                                          ",

            // Plan 5
            "Hotel: Downtown Ottawa (Days 1-3), Old Quebec City (Days 3-5)\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Parliament Hill                                                                                                  \n"
            "        - National Gallery of Canada                                                                                       \n"
            "| 2   | - Canadian Museum of History                                                                                       \n"
            "        - ByWard Market                                                                                                    \n"
            "        - (Optional) Rideau Canal cruise                                                                                   \n"
            "| 3   | - Travel to Old Quebec City                                                                                        \n"
            "        - Explore Old Town                                                                                                 \n"
            "| 4   | - Visit the Citadel                                                                                                \n"
            "        - Walk the Plains of Abraham                                                                                       \n"
            "        - Stroll Petit Champlain                                                                                           \n"
            "| 5   | - Musée national des beaux-arts du Québec\n"
            "        - Explore Quartier Saint-Jean-Baptiste                            "},

        // New Orleans 
        {
            // Plan 1
            "Hotel: French Quarter\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Explore historic French Quarter                                                                                  \n"
            "        - Wander Bourbon Street (daytime)                                                                                  \n"
            "        - Casual Creole/Cajun lunch                                                                                        \n"
            "| 2   | - Garden District stroll                                                                                           \n"
            "        - (Optional) Hop-on Hop-off bus tour                                                                               \n"
            "| 3   | - Live jazz on Frenchmen Street                                                                                    \n"
            "        - Beignets at Café Du Monde                                                  ",

            // Plan 2
            "Hotel: French Quarter or Warehouse District\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Explore French Quarter                                                                                           \n"
            "        - Mule-drawn carriage ride                                                                                         \n"
            "| 2   | - National WWII Museum                                                                                             \n"
            "        - Warehouse District exploration                                                                                   \n"
            "| 3   | - Guided Garden District walking tour                                                                              \n"
            "        - Lafayette Cemetery No. 1                                                                                         \n"
            "| 4   | - St. Charles Avenue streetcar ride                                                                                \n"
            "        - Audubon Park & Zoo                                                                                               \n"
            "| 5   | - Live jazz on Frenchmen Street                                                                                    \n"
            "        - Swamp tour                                                                 ",

            // Plan 3
            "Hotel: Boutique or historic hotel in French Quarter/Garden District\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Private French Quarter walking tour                                                                              \n"
            "        - Gourmet Creole dinner                                                                                            \n"
            "| 2   | - New Orleans Museum of Art & sculpture garden                                                                     \n"
            "        - Explore City Park                                                                                                \n"
            "| 3   | - Private Garden District tour & historic house museum                                                             \n"
            "        - Afternoon tea at grand hotel                                                                                     \n"
            "| 4   | - Scenic steamboat ride with live jazz                                                                             \n"
            "| 5   | - Culinary tour & cooking class                                                                                    \n"
            "| 6   | - Tremé & Backstreet Cultural Museum                                                                               \n"
            "        - Live brass band performance                                                                                      \n"
            "| 7   | - Ogden Museum of Southern Art                                                                                     \n"
            "        - Farewell brunch with live music                                             ",

            // Plan 4
            "Hotel: Family-friendly hotel near French Quarter/Garden District\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Explore French Quarter                                                                                           \n"
            "        - Mule-drawn carriage ride                                                                                         \n"
            "        - Beignets at Café Du Monde                                                                                        \n"
            "| 2   | - Audubon Park & Zoo                                                                                               \n"
            "        - Audubon Park train ride                                                                                          \n"
            "        - (Optional) Butterfly Garden                                                                                      \n"
            "| 3   | - St. Charles Avenue streetcar ride                                                                                \n"
            "        - Louisiana Children's Museum                                                                                      \n"
            "| 4   | - Swamp tour                                                                                                       \n"
            "        - (Optional) Mardi Gras World visit                                                             ",

            // Plan 5
            "Hotel: Guesthouse in Marigny or Bywater\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Explore Marigny neighborhood                                                                                     \n"
            "        - Live music in Marigny                                                                                            \n"
            "| 2   | - Wander Bywater neighborhood                                                                                      \n"
            "        - Visit Music Box Village                                                                                          \n"
            "| 3   | - Explore Faubourg Bouligny                                                                                        \n"
            "        - Brunch at Columns Hotel                                                                                          \n"
            "| 4   | - Bike tour through neighborhoods                                                                                  \n"
            "        - Visit St. Louis Cemetery No. 3                                                                                   \n"
            "| 5   | - Ferry to Algiers Point                                                                                           \n"
            "        - Enjoy New Orleans skyline views                                                    "},

        // Florida Keys 
        {
            // Plan 1
            "Hotel: Guesthouse or budget hotel in Key West\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Explore Duval Street                                                                                             \n"
            "        - Mallory Square sunset celebration                                                                                \n"
            "| 2   | - Ernest Hemingway Home & Museum                                                                                   \n"
            "        - Key West Butterfly Conservatory                                                                                  \n"
            "| 3   | - Relax on Smathers Beach or Fort Zachary Taylor Beach                                                             \n"
            "        - (Optional) Snorkeling trip                           ",

            // Plan 2
            "Hotel: Hotel or resort in Key Largo or Islamorada\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Drive to Key Largo                                                                                               \n"
            "        - John Pennekamp Coral Reef State Park (snorkeling/glass-bottom boat)                                              \n"
            "| 2   | - Theater of the Sea (Islamorada)                                                                                  \n"
            "        - History of Diving Museum                                                                                         \n"
            "| 3   | - Relax on an Islamorada beach                                                                                     \n"
            "        - Waterfront seafood dinner                                                                                        \n"
            "| 4   | - Drive to Marathon                                                                                                \n"
            "        - Turtle Hospital                                                                                                  \n"
            "        - Walk/bike Seven Mile Bridge                                                                                      \n"
            "| 5   | - Return to mainland or fly from Key West                                                                       ",

            // Plan 3
            "Hotel: Upscale resort in Key West, Islamorada, or Little Torch Key\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Arrive & check in                                                                                                \n"
            "        - Sunset sail with drinks                                                                                          \n"
            "| 2   | - Private snorkeling/diving charter                                                                                \n"
            "        - Explore Duval Street fine dining                                                                                 \n"
            "| 3   | - Day trip to Dry Tortugas National Park                                                                           \n"
            "| 4   | - Drive to Islamorada & watersports                                                                                \n"
            "| 5   | - Fishing charter                                                                                                  \n"
            "        - Spa treatment & gourmet seafood dinner                                                                           \n"
            "| 6   | - Explore Long Key or Bahia Honda State Park                                                                       \n"
            "        - Bird-watching & sunset cocktails                                                                                 \n"
            "| 7   | - Leisurely breakfast & departure                                                                               ",

            // Plan 4
            "Hotel: Family-friendly resort/rental in Key Largo or Marathon\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Drive to Key Largo                                                                                               \n"
            "        - John Pennekamp Coral Reef boat tour                                                                              \n"
            "        - Pool/beach time                                                                                                  \n"
            "| 2   | - Explore Theater of the Sea                                                                                       \n"
            "        - Visit Dolphins Plus                                                                                              \n"
            "| 3   | - Drive to Marathon                                                                                                \n"
            "        - Turtle Hospital                                                                                                  \n"
            "        - Play at Sombrero Beach                                                                                           \n"
            "| 4   | - Florida Keys Aquarium Encounters                                                                                 \n"
            "        - Return to mainland                                                      ",

            // Plan 5
            "Hotel: Guesthouse in Lower Keys (Big Pine Key, Bahia Honda)\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Drive to Lower Keys & check in                                                                                   \n"
            "        - Sunset from a quiet beach                                                                                        \n"
            "| 2   | - Bahia Honda State Park                                                                                           \n"
            "        - (Optional) Kayaking/paddleboarding                                                                               \n"
            "| 3   | - National Key Deer Refuge & Blue Hole exploration                                                                 \n"
            "| 4   | - Snorkeling trip to Looe Key Reef                                                                                 \n"
            "        - Enjoy local seafood dinner                                                                                       \n"
            "| 5   | - Leisurely morning & departure                                                                                 "},

        // Oahu, Hawaii 
        {
            // Plan 1
            "Hotel: Hotel in Waikiki\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | -----------------------------------------------------------------------------------------------------------------  \n"
            "| 1   | - Relax and swim at Waikiki Beach                                                                                  \n"
            "        - Learn to surf (optional lesson)                                                                                  \n"
            "        - Enjoy sunset views from Waikiki Beach                                                                            \n"
            "| 2   | - Visit Pearl Harbor (book tickets in advance)                                                                     \n"
            "        - Explore the Pearl Harbor Visitor Center                                                                          \n"
            "| 3   | - Hike Diamond Head                                                                                                \n"
            "        - Explore Kapiolani Park                                                                   ",

            // Plan 2
            "Hotel: Hotel in Waikiki\n"
            "| Day | Activities                                                                                                 \n"
            "| --- | ---------------------------------------------------------------------------------------------------------  \n"
            "| 1   | - Relax at Waikiki Beach                                                                                   \n"
            "        - Evening luau                                                                                             \n"
            "| 2   | - Visit Pearl Harbor                                                                                       \n"
            "        - Explore the Polynesian Cultural Center                                                                   \n"
            "| 3   | - Hike Diamond Head                                                                                        \n"
            "        - Explore Honolulu Zoo                                                                                     \n"
            "        - Visit the Waikiki Aquarium                                                                               \n"
            "| 4   | - Drive the Windward Coast: Hanauma Bay, Halona Blowhole, Sandy Beach                                      \n"
            "        - Visit Byodo-In Temple                                                                                    \n"
            "| 5   | - Explore historic Honolulu (Iolani Palace, King Kamehameha Statue)                                        \n"
            "        - Visit the Honolulu Museum of Art ",

            // Plan 3
            "Hotel: Luxury resort in Waikiki or Ko Olina\n"
            "| Day | Activities                                                                                                 \n"
            "| --- | -------------------------------------------------------------------------------------------------          \n"
            "| 1   | - Arrive, check in, relax by pool or beach                                                                 \n"
            "        - Sunset cocktails                                                                                         \n"
            "| 2   | - Private surf lesson or outrigger canoe experience                                                        \n"
            "        - Luxury catamaran cruise                                                                                  \n"
            "        - Fine dining                                                                                              \n"
            "| 3   | - Day trip to North Shore: Waimea Bay, Sunset Beach, Banzai Pipeline                                       \n"
            "        - Lunch at a shrimp truck                                                                                  \n"
            "| 4   | - In-depth Pearl Harbor tour: USS Arizona Memorial, Battleship Missouri, Pacific Aviation Museum           \n"
            "| 5   | - Private Diamond Head sunrise hike                                                                        \n"
            "        - Manoa Falls Trail and Lyon Arboretum visit                                                               \n"
            "| 6   | - Helicopter tour of the island                                                                            \n"
            "        - Spa treatment                                                                                            \n"
            "        - Gourmet Hawaiian fusion dinner                                                                           \n"
            "| 7   | - Leisurely breakfast                                                                                      \n"
            "        - Depart Waikiki                                                         ",

            // Plan 4
            "Hotel: Family-friendly resort in Waikiki or Ko Olina\n"
            "| Day | Activities                                                                         \n"
            "| --- | ---------------------------------------------------------------------------        \n"
            "| 1   | - Relax at Waikiki Beach: build sandcastles, swim                                  \n"
            "        - Visit Honolulu Zoo                                                               \n"
            "| 2   | - Pearl Harbor: USS Arizona Memorial and USS Bowfin Submarine Museum & Park        \n"
            "| 3   | - Full day at the Polynesian Cultural Center                                       \n"
            "| 4   | - Hike Makapu'u Point Lighthouse Trail                                             \n"
            "        - Visit Sea Life Park Hawaii                                                       \n"
            "| 5   | - Catamaran cruise with optional snorkeling                                        \n"
            "        - Picnic lunch on board      ",

            // Plan 5
            "Hotel: Hotel/rental on North Shore (Days 1-3), Hotel in Waikiki (Days 3-5)\n"
            "| Day | Activities                                                                                                             \n"
            "| --- | --------------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Drive to North Shore                                                                                                 \n"
            "        - Relax on Waimea Bay & Sunset Beach                                                                                   \n"
            "| 2   | - Explore Hale'iwa town                                                                                                \n"
            "        - Visit Waimea Valley waterfalls                                                                                       \n"
            "        - Lunch at a shrimp truck                                                                                              \n"
            "| 3   | - Drive through Dole Plantation grounds en route to Waikiki                                                            \n"
            "        - Check in and evening stroll on Kalakaua Avenue                                                                       \n"
            "| 4   | - Hike Diamond Head                                                                                                    \n"
            "        - Visit the Honolulu Museum of Art                                                                                     \n"
            "        - Explore Chinatown                                                                                                    \n"
            "| 5   | - Morning visit to Pearl Harbor (if missed earlier)                                                                    \n"
            "        - Final swim and relaxation at Waikiki Beach before departure ",
        },

        // Las Vegas 
        {
            // Plan 1
            "Hotel: Budget-friendly hotel on or near the Strip\n"
            "| Day | Activities                                                                                                     \n"
            "| --- | ----------------------------------------------------------------------------------------------------------     \n"
            "| 1   | - Explore the Las Vegas Strip                                                                                  \n"
            "        - Watch the Bellagio Fountains                                                                                 \n"
            "        - Enjoy a casual buffet dinner                                                                                 \n"
            "| 2   | - Visit the High Roller Observation Wheel                                                                      \n"
            "        - Explore the LINQ Promenade                                                                                   \n"
            "        - See a budget-friendly show                                                                                   \n"
            "| 3   | - Explore the Fremont Street Experience                                                                        \n"
            "        - See the Viva Vision light show                                                                               \n"
            "        - Enjoy cheap eats downtown ",

            // Plan 2
            "Hotel: Mid-range hotel on the Strip\n"
            "| Day | Activities                                                                                                     \n"
            "| --- | -----------------------------------------------------------------------------------------------------------    \n"
            "| 1   | - Explore the South Strip (Welcome Sign, Luxor, Mandalay Bay)                                                  \n"
            "        - See a lower-priced Cirque du Soleil show                                                                     \n"
            "| 2   | - Explore the Mid-Strip (Bellagio, Caesars, Venetian)                                                          \n"
            "        - Ride the High Roller                                                                                         \n"
            "| 3   | - Day trip to the Hoover Dam                                                                                   \n"
            "        - Learn about the dam's history                                                                                \n"
            "| 4   | - Explore the North Strip (The STRAT, Resorts World)                                                           \n"
            "        - Visit a museum (e.g. Mob Museum)                                                                             \n"
            "| 5   | - Explore Fremont Street Experience (day & night)                                                              \n"
            "        - Optional: Zipline downtown                           ",
            // Plan 3
            "Hotel: Luxury hotel on the Strip\n"
            "| Day | Activities                                                                                                     \n"
            "| --- | -----------------------------------------------------------------------------------------------------          \n"
            "| 1   | - Arrive, check in, relax by pool or explore hotel                                                             \n"
            "        - Gourmet dinner                                                                                               \n"
            "| 2   | - See a top-tier Cirque du Soleil show                                                                         \n"
            "        - High-end shopping & cocktails                                                                                \n"
            "| 3   | - Day trip to the Grand Canyon (airplane or helicopter tour)                                                   \n"
            "| 4   | - Explore luxury resorts (Bellagio Conservatory, Venetian canals)                                              \n"
            "        - Spa treatment & headliner show                                                                               \n"
            "| 5   | - Visit Neon Museum & Pinball Hall of Fame                                                                     \n"
            "        - Explore Arts District & wine tasting                                                                         \n"
            "| 6   | - High-roller activities (VIP club, private table)                                                             \n"
            "        - Gourmet food tour                                                                                            \n"
            "| 7   | - Leisurely breakfast                                                                                          \n"
            "        - Departure                                                                  ",

            // Plan 4
            "Hotel: Family-friendly hotel on or near the Strip\n"
            "| Day | Activities                                                                                                                     \n"
            "| --- | -----------------------------------------------------------------------------------------------------------------------------  \n"
            "| 1   | - Explore themed resorts (Bellagio fountains, Mirage volcano, Venetian canals)                                                 \n"
            "        - Visit the High Roller (daytime)                                                                                              \n"
            "| 2   | - Visit family attraction (Shark Reef Aquarium, Avengers S.T.A.T.I.O.N.)                                                       \n"
            "        - Explore the LINQ Promenade (kid-friendly shops)                                                                              \n"
            "| 3   | - Day trip to Springs Preserve or Red Rock Canyon (scenic drive)                                                               \n"
            "| 4   | - Explore Fremont Street Experience (daytime)                                                                                  \n"
            "        - Visit Discovery Children's Museum                                                                                            \n"
            "        - Enjoy a family-friendly show        ",

            // Plan 5
            "Hotel: Hotel or Airbnb off the main Strip\n"
            "| Day | Activities                                                                 \n"
            "| --- | ------------------------------------------------------------------------   \n"
            "| 1   | - Explore the Arts District                                                \n"
            "        - Visit the Neon Museum Boneyard                                           \n"
            "| 2   | - Visit the Pinball Hall of Fame                                           \n"
            "        - Explore Antique Row                                                      \n"
            "| 3   | - Hike in Red Rock Canyon                                                  \n"
            "        - Visit Spring Mountain Ranch State Park                                   \n"
            "| 4   | - Explore Valley of Fire State Park                                        \n"
            "| 5   | - Visit Seven Magic Mountains                                              \n"
            "        - Explore a local brewery or distillery ",
        },

        // New York City
        {
            // Plan 1
            "Hotel: Budget-friendly hotel in Midtown or Long Island City\n"
            "| Day | Activities                                                                                                             \n"
            "| --- | -------------------------------------------------------------------------------------------------------------------    \n"
            "| 1   | - Visit Times Square                                                                                                   \n"
            "        - Walk through Central Park                                                                                            \n"
            "        - See a Broadway show (budget/lottery)                                                                                 \n"
            "| 2   | - Statue of Liberty & Ellis Island                                                                                     \n"
            "        - Explore Financial District & Charging Bull                                                                           \n"
            "        - Walk across Brooklyn Bridge                                                                                          \n"
            "| 3   | - Top of the Rock observation deck                                                                                     \n"
            "        - Explore Rockefeller Center                                                                                           \n"
            "        - Wander through Greenwich Village            ",
            // Plan 2
            "Hotel: Mid-range hotel in Midtown, Chelsea, or Lower East Side\n"
            "| Day | Activities                                                                                                     \n"
            "| --- | ----------------------------------------------------------------------------------------------------------     \n"
            "| 1   | - Metropolitan Museum of Art (The Met)                                                                         \n"
            "        - Explore Central Park                                                                                         \n"
            "| 2   | - Museum of Modern Art (MoMA)                                                                                  \n"
            "        - Times Square & Theater District                                                                              \n"
            "        - See a Broadway show                                                                                          \n"
            "| 3   | - 9/11 Memorial & Museum (book ahead)                                                                          \n"
            "        - One World Observatory                                                                                        \n"
            "        - Walk Brooklyn Bridge & explore DUMBO                                                                         \n"
            "| 4   | - Greenwich Village & Washington Square Park                                                                   \n"
            "        - Visit SoHo                                                                                                   \n"
            "        - Explore Little Italy & Chinatown                                                                             \n"
            "| 5   | - Staten Island Ferry ride                                                                                     \n"
            "        - Explore Brooklyn (Williamsburg or Park Slope)                                                                \n"
            "        - Visit Chelsea Market    ",
            // Plan 3
            "Hotel: Luxury hotel in Midtown or near Central Park\n"
            "| Day | Activities                                                                                                                 \n"
            "| --- | -------------------------------------------------------------------------------------------------------------------------  \n"
            "| 1   | - Private guided tour of The Met                                                                                           \n"
            "        - Horse-drawn carriage ride in Central Park                                                                                \n"
            "        - High-end Broadway show & gourmet dinner                                                                                  \n"
            "| 2   | - Private MoMA tour                                                                                                        \n"
            "        - Guided Rockefeller Center tour                                                                                           \n"
            "        - Top of the Rock at sunset & rooftop cocktails                                                                            \n"
            "| 3   | - Private 9/11 Memorial & Museum tour                                                                                      \n"
            "        - Explore Financial District & private Federal Reserve visit                                                               \n"
            "| 4   | - Upper East Side museums (Frick Collection, Guggenheim)                                                                   \n"
            "        - High tea at a luxury hotel                                                                                               \n"
            "        - Evening Lincoln Center show                                                                                              \n"
            "| 5   | - Greenwich Village, SoHo & NoLita with a local expert                                                                     \n"
            "        - Private Chelsea art gallery tour                                                                                         \n"
            "        - Gourmet dinner in SoHo                                                                                                   \n"
            "| 6   | - Day trip to Dia:Beacon or Storm King Art Center (private car)                                                            \n"
            "        - Scenic Hudson River views                                                                                                \n"
            "        - Farewell dinner                                                                                                          \n"
            "| 7   | - Leisurely brunch                                                                                                         \n"
            "        - Explore a neighborhood of your choice                                                                                    \n"
            "        - Departure                                                 ",
            // Plan 4
            "Hotel: Family-friendly hotel in Midtown or near attractions\n"
            "| Day | Activities                                                                                                             \n"
            "| --- | --------------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Times Square visit                                                                                                   \n"
            "        - Central Park (Zoo, carousel, playground)                                                                             \n"
            "        - Family-friendly Broadway show                                                                                        \n"
            "| 2   | - American Museum of Natural History                                                                                   \n"
            "        - Explore Upper West Side                                                                                              \n"
            "        - Optional: New-York Historical Society                                                                                \n"
            "| 3   | - Statue of Liberty & Ellis Island                                                                                     \n"
            "        - SeaGlass Carousel at Battery Park                                                                                    \n"
            "        - Walk Brooklyn Bridge & pizza in DUMBO                                                                                \n"
            "| 4   | - Intrepid Sea, Air & Space Museum                                                                                     \n"
            "        - Explore Little Italy or Chinatown                                                                                    \n"
            "        - Enjoy ice cream or other treats       ",
            // Plan 5
            "Hotel: Boutique hotel or Airbnb in Brooklyn (Williamsburg/Bushwick) or Queens (LIC/Astoria)\n"
            "| Day | Activities                                                                                                 \n"
            "| --- | ---------------------------------------------------------------------------------------------------------  \n"
            "| 1   | - Williamsburg: street art, shops, waterfront                                                              \n"
            "        - Local brewery visit                                                                                      \n"
            "        - Skyline dinner                                                                                           \n"
            "| 2   | - Bushwick: street art tour                                                                                \n"
            "        - Unique Brooklyn museum                                                                                   \n"
            "        - Diverse Bushwick cuisine                                                                                 \n"
            "| 3   | - Long Island City: Gantry Plaza State Park, MoMA PS1                                                      \n"
            "        - Rooftop bar experience                                                                                   \n"
            "| 4   | - Astoria: food scene, Museum of the Moving Image                                                          \n"
            "        - Socrates Sculpture Park                                                                                  \n"
            "        - Greek food tasting                                                                                       \n"
            "| 5   | - Ferry to Governors Island                                                                                \n"
            "        - Lower East Side: Tenement Museum                                                                         \n"
            "        - Final pizza slice before departure ",
        },

        // Crete, Greece 
        {
            // Plan 1
            "Hotel: Budget-friendly hotel or guesthouse in Heraklion\n"
            "| Day | Activities                                                                                                                                     \n"
            "| --- | ---------------------------------------------------------------------------------------------------------------------------------------------  \n"
            "| 1   | - Explore Heraklion: Venetian Harbour, Koules Fortress, Old Town                                                                               \n"
            "        - Visit Heraklion Archaeological Museum                                                                                                        \n"
            "        - Enjoy a casual Cretan dinner                                                                                                                 \n"
            "| 2   | - Visit the Palace of Knossos                                                                                                                  \n"
            "        - Explore the local markets in Heraklion                                                                                                       \n"
            "| 3   | - Relax on a nearby beach (e.g. Ammoudara)                                                                                                     \n"
            "        - Enjoy a final Cretan meal                                                                    ",
            // Plan 2
            "Hotel: Hotel or guesthouse in Chania\n"
            "| Day | Activities                                                                                                                                     \n"
            "| --- | ------------------------------------------------------------------------------------------------------------------------------------------     \n"
            "| 1   | - Explore Chania Old Town: Venetian Harbour, lighthouse, narrow streets                                                                        \n"
            "        - Visit Chania Archaeological Museum                                                                                                           \n"
            "        - Dinner by the harbour                                                                                                                        \n"
            "| 2   | - Day trip to Balos Lagoon & Gramvousa Island (boat recommended)                                                                               \n"
            "        - Beach time and scenic views                                                                                                                  \n"
            "| 3   | - Hike part of the Samaria Gorge (full day; fitness required)                                                                                  \n"
            "        - Alternative: explore smaller gorges                                                                                                          \n"
            "| 4   | - Relax on a beach west of Chania (e.g. Agioi Apostoloi)                                                                                       \n"
            "        - Visit nearby villages                                                                                                                        \n"
            "| 5   | - Optional visit to Limnoupolis Water Park                                                                                                     \n"
            "        - Final Cretan dinner in Chania                                                              ",
            // Plan 3
            "Hotel: Upscale resort in Elounda or Agios Nikolaos\n"
            "| Day | Activities                                                                                                             \n"
            "| --- | ------------------------------------------------------------------------------------------------------------------     \n"
            "| 1   | - Arrive in East Crete & check in                                                                                      \n"
            "        - Relax by the pool or beach                                                                                           \n"
            "        - Gourmet dinner at the resort                                                                                         \n"
            "| 2   | - Visit Spinalonga Island                                                                                              \n"
            "        - Explore Agios Nikolaos & Lake Voulismeni                                                                             \n"
            "| 3   | - Day trip to Lassithi Plateau: windmills, villages & Dikteon Cave                                                     \n"
            "        - Enjoy inland scenery & local crafts                                                                                  \n"
            "| 4   | - Relax on Elounda beaches (e.g. Plaka)                                                                                \n"
            "        - Optional boat trip to nearby coves                                                                                   \n"
            "| 5   | - Visit the Minoan Palace of Malia                                                                                     \n"
            "        - Explore the traditional village of Kritsa                                                                            \n"
            "        - Join a Cretan cooking class                                                                                          \n"
            "| 6   | - Hike Richtis Gorge                                                                                                   \n"
            "        - Tour a local olive oil farm                                                                                          \n"
            "        - Farewell dinner with sea views                                                                                       \n"
            "| 7   | - Leisurely breakfast                                                                                                  \n"
            "        - Departure                                                                               ",
            // Plan 4
            "Hotel: Guesthouse in a South Crete town (e.g. Matala, Agia Galini)\n"
            "| Day | Activities                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------     \n"
            "| 1   | - Drive to South Crete & check in                                                                  \n"
            "        - Explore Matala's beaches & caves                                                                 \n"
            "        - Dinner by the sea                                                                                \n"
            "| 2   | - Hike to Preveli Palm Beach (via gorge or boat)                                                   \n"
            "        - Swim at the river mouth                                                                          \n"
            "| 3   | - Explore Agia Galini village                                                                      \n"
            "        - Boat trip along the south coast to secluded beaches                                              \n"
            "| 4   | - Hike a section of the E4 mountain path                                                           \n"
            "        - Visit the archaeological site of Phaistos                                                        \n"
            "| 5   | - Relax on a south coast beach (e.g. Plakias)                                                      \n"
            "        - Final Cretan meal in a taverna             ",

            // Plan 5
            "Hotel: Hotel or guesthouse in Rethymno Old Town\n"
            "| Day | Activities                                                                                                                                 \n"
            "| --- | -----------------------------------------------------------------------------------------------------------------------------------------  \n"
            "| 1   | - Explore Rethymno Old Town: Venetian Harbour, Fortezza, narrow streets                                                                    \n"
            "        - Visit Rethymno Archaeological Museum                                                                                                     \n"
            "        - Dinner in Old Town                                                                                                                       \n"
            "| 2   | - Relax on Rethymno beach                                                                                                                  \n"
            "        - Optional water sports                                                                                                                    \n"
            "| 3   | - Day trip to Arkadi Monastery                                                                                                             \n"
            "        - Explore traditional villages in Amari Valley                                                                                             \n"
            "        - Lunch in a mountain village                                                                                                              \n"
            "| 4   | - Visit Melidoni Cave                                                                                                                      \n"
            "        - Tour Margarites pottery village                                                                                                          \n"
            "        - Cooking demonstration & Cretan meal                                                                                                      \n"
            "| 5   | - See the Venetian Loggia & Rimondi Fountain                                                                                               \n"
            "        - Final stroll through Old Town before departure                                          ",
        },

        // Barcelona 
        {
            // Plan 1
            "Hotel: Budget-friendly hotel or hostel in the Gothic Quarter or El Raval\n"
            "| Day | Activities                                                                                             \n"
            "| --- | --------------------------------------------------------------------------------------------------     \n"
            "| 1   | - Explore the Gothic Quarter                                                                           \n"
            "        - Stroll along La Rambla                                                                               \n"
            "        - Enjoy tapas at a local bar                                                                           \n"
            "| 2   | - Visit Park Güell (book ahead)                                                                        \n"
            "        - Admire Sagrada Família (exterior)                                                                    \n"
            "        - Wander through El Born                                                                               \n"
            "| 3   | - Visit the Picasso Museum                                                                             \n"
            "        - Relax on Barceloneta Beach                                                                           \n"
            "        - Enjoy a final Spanish meal         ",

            // Plan 2
            "Hotel: Mid-range hotel in Eixample or El Born\n"
            "| Day | Activities                                                                                             \n"
            "| --- | ---------------------------------------------------------------------------------------------------    \n"
            "| 1   | - Explore the Gothic Quarter                                                                           \n"
            "        - Visit Barcelona History Museum (MUHBA)                                                               \n"
            "        - Enjoy a paella dinner                                                                                \n"
            "| 2   | - Visit Sagrada Família (book ahead to go inside)                                                      \n"
            "        - View Casa Batlló & Casa Milà (La Pedrera)                                                            \n"
            "| 3   | - Visit Park Güell                                                                                     \n"
            "        - Explore the Gràcia neighborhood                                                                      \n"
            "| 4   | - Relax on Barceloneta Beach                                                                           \n"
            "        - Take Montjuïc cable car                                                                              \n"
            "        - Visit Magic Fountain of Montjuïc                                                                     \n"
            "| 5   | - Visit the Picasso Museum                                                                             \n"
            "        - Explore El Born (Santa Maria del Mar)                                                                \n"
            "        - Enjoy tapas & wine tasting ",

            // Plan 3
            "Hotel: Luxury hotel in Passeig de Gràcia or the Gothic Quarter\n"
            "| Day | Activities                                                                                                                                 \n"
            "| --- | ---------------------------------------------------------------------------------------------------------------------------------------    \n"
            "| 1   | - Private guided tour of the Gothic Quarter                                                                                                \n"
            "        - Gourmet Catalan dinner                                                                                                                   \n"
            "| 2   | - Private guided tour of Sagrada Família & Gaudí                                                                                           \n"
            "        - High-end shopping on Passeig de Gràcia                                                                                                   \n"
            "        - Rooftop cocktails                                                                                                                        \n"
            "| 3   | - Private guided tour of Park Güell                                                                                                        \n"
            "        - Explore Gaudí House Museum                                                                                                               \n"
            "        - Enjoy a Catalan cooking class                                                                                                            \n"
            "| 4   | - Visit Joan Miró Foundation                                                                                                               \n"
            "        - Explore National Art Museum of Catalonia (MNAC)                                                                                          \n"
            "        - Enjoy the Magic Fountain show (VIP if available)                                                                                         \n"
            "| 5   | - Explore El Born with a local expert                                                                                                      \n"
            "        - Visit Palau de la Música Catalana                                                                                                        \n"
            "        - Enjoy tapas & wine tasting                                                                                                               \n"
            "| 6   | - Day trip to Montserrat Monastery                                                                                                         \n"
            "        - Enjoy a traditional Catalan lunch                                                                                                        \n"
            "| 7   | - Visit FC Barcelona Museum & Camp Nou (optional)                                                                                          \n"
            "        - Relax on a leisurely morning                                                                                                             \n"
            "        - Farewell dinner                                ",
            // Plan 4
            "Hotel: Family-friendly hotel or apartment near attractions\n"
            "| Day | Activities                                                                                                         \n"
            "| --- | ----------------------------------------------------------------------------------------------------------------   \n"
            "| 1   | - Explore Park Güell                                                                                               \n"
            "        - Visit Barcelona Aquarium                                                                                         \n"
            "        - Stroll along La Rambla                                                                                           \n"
            "| 2   | - Visit Tibidabo Amusement Park                                                                                    \n"
            "        - Take the Tramvia Blau & funicular                                                                                \n"
            "| 3   | - Relax on Barceloneta Beach                                                                                       \n"
            "        - Visit Barcelona Zoo                                                                                              \n"
            "        - Enjoy a picnic                                                                                                   \n"
            "| 4   | - Visit Magic Fountain of Montjuïc                                                                                 \n"
            "        - Explore Montjuïc Hill (cable car optional)                                                                       \n"
            "        - Optional: Poble Espanyol ",

            // Plan 5
            "Hotel: Boutique guesthouse in Gràcia or Sant Antoni\n"
            "| Day | Activities                                                                                                                                 \n"
            "| --- | --------------------------------------------------------------------------------------------------------------------------------------     \n"
            "| 1   | - Explore the Gràcia neighborhood                                                                                                          \n"
            "        - Visit Gaudí's Casa Vicens                                                                                                                \n"
            "        - Enjoy dinner in Gràcia                                                                                                                   \n"
            "| 2   | - Explore the Sant Antoni neighborhood                                                                                                     \n"
            "        - Visit Fundació Joan Miró                                                                                                                 \n"
            "| 3   | - Walk Passeig de Gràcia (exterior Gaudí sites)                                                                                            \n"
            "        - Visit Palau Robert gardens                                                                                                               \n"
            "        - Enjoy a vermouth tasting                                                                                                                 \n"
            "| 4   | - Explore El Raval (street art hunt)                                                                                                       \n"
            "        - Visit MACBA                                                                                                                              \n"
            "        - Local café stop                                                                                                                          \n"
            "| 5   | - Day trip to Montserrat Monastery                                                                                                         \n"
            "        - Scenic mountain views                                                                                                                    \n"
            "        - Farewell tapas & cava                                                "}};
    const char *hotels[NUM_CITIES][NUM_HOTELS] = {
        {"Ibis Paris Tour Eiffel Cambronne 15eme - Rs.14,255",
         "Novotel Paris Centre Tour Eiffel - Rs.21,854",
         "Hotel De Castiglione - Rs.17,360",
         "Shangri-La Paris - Rs.1,67,197",
         "Four Seasons Hotel George V, Paris - Rs.2,58,021"},
        {"Kempinski Central Avenue Dubai - Rs.9,593",
         "Radisson Blu Hotel, Dubai Waterfront - Rs.7,984",
         "Burj al arab jumeirah Hotel - Rs.23,993",
         "FIVE Palm Jumeirah Hotel - Rs.23,249",
         "The Canvas Dubai- MGallery Hotel Collection - Rs.4,698"},
        {"DoubleTree by Hilton London - Tower of London - Rs.10,977",
         "The Waldorf Hilton, London - Rs.22,772",
         "The Lalit London - Rs.14,183",
         "DoubleTree by Hilton London - West End - Rs.14,976",
         "Novotel London Canary Wharf - Rs.14,203"},
        {"hotel MONday TOKYO NISHIKASAI - Rs.4,094",
         "Rembrandt Hotel Tokyo Machida - Rs.4,549",
         "The Prince Park Tower Tokyo - Rs.24,545",
         "Conrad Tokyo - Rs.49,718",
         "Imperial Hotel Tokyo - Rs.31,828"},
        {"Palazzo Manfredi - Rs.86,901",
         "The Church Palace - Rs.8,095",
         "B&B HOTEL Roma Trastevere - Rs.7,651",
         "Hotel Artemide - Rs.31,243",
         "Hotel Villa San Lorenzo Maria - Rs.6,313"},
        {"Harbour Grand Hong Kong - Rs.7,481",
         "The Salisbury - YMCA of Hong Kong - Rs.7,490",
         "Regal Hongkong Hotel - Rs.8,250",
         "Hotel COZi ‧ Harbour View - Rs.4,049",
         "Cordis, Hong Kong - Rs.10,327"},
        {"Sheraton Buenos Aires Hotel & Convention Center - Rs.10,327",
         "Four Seasons Hotel Buenos Aires - Rs.61,310",
         "Sofitel Buenos Aires Recoleta - Rs.14,868",
         "Park Tower, a Luxury Collection Hotel, Buenos Aires - Rs.13,226",
         "Hotel NH Buenos Aires City - Rs.6,935"},
        {"108 Golf Resort - Rs.1,393",
         "Hygie Hotel - Rs.4,310",
         "Midtown Inn - Rs.2,695",
         "Pangea Pod Hotel - Rs.5,739",
         "Divya Sutra Plaza and Conference Centre, Vernon, BC - Rs.3,542"},
        {"Hilton New Orleans Riverside - Rs.8,697",
         "Sheraton New Orleans Hotel - Rs.9,338",
         "Hilton Garden Inn New Orleans French Quarter/CBD - Rs.7,258",
         "HI New Orleans Hostel - Rs.4,749",
         "Holiday Inn Express New Orleans - Arts District by IHG - Rs.5,897"},
        {"Best Western Gateway to the Keys - Rs.7,637",
         "Seashell Motel - Rs.10,454",
         "Quality Inn Florida City - Gateway to the Keys - Rs.6,812",
         "Courtyard Faro Blanco Resort - Rs.24,586",
         "Little Palm Island Resort & Spa - Rs.2,09,679"},
        {"Stay Hotel Waikiki - Rs.9,675",
         "Waikiki Resort Hotel - Rs.15,358",
         "Hilton Hawaiian Village Waikiki Beach Resort - Rs.23,128",
         "Waikiki Monarch Hotel - Rs.10,469",
         "Coconut Waikiki Hotel - Rs.12,522"},
        {"The Venetian Resort Las Vegas - Rs.24,475",
         "Bellagio - Rs.30,345",
         "The LINQ Hotel + Experience - Rs.8,355",
         "Circus Circus Hotel, Casino & Theme Park - Rs.5,739",
         "Treasure Island - TI Hotel & Casino, a Radisson Hotel - Rs.11,357"},
        {"New York Marriott Marquis - Rs.28,461",
         "Holiday Inn New York City - Times Square by IHG - Rs.14,607",
         "The Westin New York at Times Square - Rs.25,814",
         "Hyatt Grand Central New York - Rs.20,799",
         "The Ritz-Carlton New York, Central Park - Rs.56,116"},
        {"Grecotel LUXME White - Rs.34,847",
         "Stella Island Resort & Spa (Adults Only) - Rs.39,461",
         "The Royal Senses Resort & Spa Crete, Curio Collection by Hilton - Rs.31,754",
         "The GDM Island Hotel (Adults Only Hotel) - Rs.11,672",
         "Amirandes, A Grecotel Resort to Live - Rs.24,258"},
        {"W Barcelona - Rs.33,704",
         "Sercotel Porta Barcelona - Rs.6,315",
         "InterContinental Barcelona by IHG - Rs.26,962",
         "Travelodge Barcelona Fira - Rs.6,006",
         "Hotel NH Collection Barcelona Gran Hotel Calderón - Rs.21,226"}

    };

    const char *activities[NUM_CITIES][NUM_ACTIVITIES] = {
        {"Eiffel Tower Ticket (Adult, elevator to 2nd floor) - Rs.1,898",
         "Louvre Museum Ticket (General Admission) - Rs.1,930",
         "Seine River Cruise (1-hour panoramic) - Rs.1,324",
         "Palace of Versailles Ticket (Full Access) - Rs.1,798",
         "Paris Catacombs Ticket (Full Rate with audioguide) - Rs.2,763"},
        {"Desert Safari (Standard Evening Safari) - Rs.2,500",
         "Burj Khalifa Observation Deck (Levels 124 & 125) - Rs.3,764",
         "Dubai Aquarium & Underwater Zoo (General Admission) - Rs.2,756",
         "Dubai Frame - Rs.1,136",
         "Museum of the Future - Rs.3,390"},
        {"London Eye Ticket (Standard Adult) - Rs.3,345",
         "Tower of London Ticket (Adult) - Rs.3,988",
         "British Museum (General Admission) - Free (guided tours Rs.2,000)",
         "West End Show (e.g., The Phantom of the Opera) - Rs.3,880",
         "Buckingham Palace State Rooms Tour (Adult) - Rs.1,970"},
        {"Tokyo Skytree (Tembo Deck + Tembo Galleria) - Rs. 2,650",
         "Shibuya Sky (Observation Deck) - Rs. 1,600",
         "TeamLab Planets TOKYO DMM - Rs. 1,900",
         "Tokyo Disneyland / DisneySea (1-Day Passport) - Rs. 5,000",
         "Meiji Jingu Shrine (Admission) - Free (some special exhibits may have a fee)"},
        {"Colosseum, Roman Forum, & Palatine Hill Ticket (basic entry) - Rs. 2,177",
         "Vatican Museums & Sistine Chapel Ticket - Rs. 3,888",
         "Borghese Gallery & Museum (Standard Entry) - Rs. 2,595",
         "Trevi Fountain Underground Tour (basic) - Rs. 740",
         "Pantheon (Skip-the-Line Ticket) - Rs. 1,275"},
        {"Victoria Peak Tram Sky Pass (Round-trip tram + Sky Terrace 428) - Rs. 1,500",
         "Ocean Park Hong Kong (General Admission) - Rs. 5,000",
         "Ngong Ping 360 Cable Car (Standard Cabin, Round-trip) - Rs. 2,200",
         "Hong Kong Disneyland (1-Day Ticket) - Rs. 7,500",
         "Star Ferry (Tsim Sha Tsui to Central) - Rs. 400"},
        {"Tango Show with Dinner (e.g., Esquina Carlos Gardel) - Rs. 9,000",
         "Recoleta Cemetery (Guided Tour) - Rs. 1,200",
         "Buenos Aires City Tour (Half-day bus tour) - Rs. 2,500",
         "Museo Nacional de Bellas Artes (National Museum of Fine Arts) - Free",
         "Palermo Parks (Rent a bike) -Rs. 8000"},
        {"CN Tower (General Admission) - Rs. 3,500",
         "Ripley's Aquarium of Canada (General Admission) - Rs. 3,000",
         "Royal Ontario Museum (ROM) (General Admission) - Rs. 1,800",
         "Toronto Zoo (General Admission) - Rs. 2,000",
         "Casa Loma (Admission) - Rs. 1,900"},
        {"French Quarter Walking Tour (Historical/Ghost Tour) - Rs. 2,000",
         "Steamboat Natchez Jazz Cruise (Daytime Cruise) - Rs. 4,500",
         "Audubon Zoo (General Admission) - Rs. 2,800",
         "National WWII Museum (General Admission) - Rs. 3,500",
         "New Orleans Cemetery Tour (e.g., St. Louis Cemetery No. 1) - Rs. 2,500"},
        {"Snorkeling Tour (Key Largo) - Rs. 5,830",
         "Ernest Hemingway Home and Museum (Key West) - Rs. 1,580",
         "Key West Sunset Sail (with drinks/appetizers) -  Rs. 6,929",
         "John Pennekamp Coral Reef State Park (Vehicle Entry) - Rs. 665 (per vehicle + Rs. 50 per person)",
         "Dolphin Research Center (General Admission, Marathon) - Rs. 2,920"},
        {"Pearl Harbor USS Arizona Memorial (Tours start from) - Rs. 5,008",
         "Polynesian Cultural Center (Islands of Polynesia admission) - Rs. 7,920",
         "Waikiki Group Surfing Lesson - Rs. 8,681",
         "Diamond Head State Monument (Permit only) - Rs. 830 (for non-Hawaii residents per person)",
         "Hanauma Bay Nature Preserve (Entry fee) - Rs. 1,660"},
        {"High Roller Observation Wheel (Daytime Ticket) - Rs. 2,500",
         "Fremont Street Experience (Zipline Zoom) - Rs. 3,300",
         "Grand Canyon South Rim Bus Tour (from Las Vegas) - Rs. 14,000",
         "Cirque du Soleil Show -  Rs. 7,000",
         "Bellagio Conservatory & Botanical Garden - Free"},
        {"Empire State Building Observatory (86th Floor) - Rs. 4,200",
         "Statue of Liberty & Ellis Island Ferry (Pedestal Access) - Rs. 2,500",
         "Broadway Show (e.g., Wicked, The Lion King) - From Rs. 8,000",
         "Metropolitan Museum of Art (The Met) - Rs. 2,500 (suggested admission for non-NY residents)",
         "Top of the Rock Observation Deck - Rs. 3,800"},
        {"Knossos Palace (Archaeological Site Entrance) - Rs. 1,400",
         "Samaria Gorge Hike (Bus Transfer + Park Entrance) - From Rs. 4,000",
         "Balos Lagoon & Gramvousa Island Boat Trip - From Rs. 4,500",
         "Elafonisi Beach (Parking) - Free (some organized beach services extra)",
         "CretAquarium (General Admission) - Rs. 1,100"},
        {"Sagrada Familia (Basic Ticket) - Rs. 2,800",
         "Park Güell (Monumental Zone Ticket) - Rs. 1,050",
         "Casa Batlló (Blue Ticket) - Rs. 4,500",
         "Camp Nou Experience (Basic Tour) - Rs. 3,800",
         "Gothic Quarter Walking Tour (Free walking tours available, tips expected) - Rs. 0"}};

int isValidDate(const char *date) {
    int y, m, d;
    if (sscanf(date, "%4d-%2d-%2d", &y, &m, &d) != 3) return 0;
    if (y < 2024 || m < 1 || m > 12 || d < 1 || d > 31) return 0;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return 0;
    if (m == 2) {
        int leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
        if (d > (leap ? 29 : 28)) return 0;
    }

    int currentY = 2025, currentM = 5, currentD = 26;
    if (y < currentY || (y == currentY && m < currentM) || (y == currentY && m == currentM && d < currentD)) {
        return 0;
    }

    return 1;
}

int compareDates(const char *start, const char *end) {
    int sy, sm, sd, ey, em, ed;
    sscanf(start, "%4d-%2d-%2d", &sy, &sm, &sd);
    sscanf(end, "%4d-%2d-%2d", &ey, &em, &ed);
    if (ey > sy) return 1;
    if (ey == sy && em > sm) return 1;
    if (ey == sy && em == sm && ed > sd) return 1;
    return 0;
}

int getValidDate(const char *prompt, char *dateBuffer) {
    int valid = 0;
    while (!valid) {
        printf("%s", prompt);
        scanf("%19s", dateBuffer);
        valid = isValidDate(dateBuffer);
        if (!valid) {
            printf("Invalid date. Must be in format YYYY-MM-DD and not in the past.\n");
        }
    }
    return 1;
}

int getValidAge() {
    char input[100];
    int age;
    char extra;

    while (1) {
        printf("  Age: ");
        if (!fgets(input, sizeof(input), stdin)) {
            printf("  Invalid input. Please try again.\n");
            continue;
        }

        if (sscanf(input, "%d %c", &age, &extra) != 1 || age <= 0 || age > 120) {
            printf("  Invalid age. Please enter a valid age.\n");
        } else {
            break;
        }
    }

    return age;
}

void getValidMobile(char *mobile) {
    int valid = 0;
    while (!valid) {
        valid = 1;
        printf("  Mobile Number: ");
        scanf("%s", mobile);
        for (int j = 0; mobile[j] != '\0'; j++) {
            if (!isdigit(mobile[j])) {
                valid = 0;
                break;
            }
        }
        if (!valid) printf("Invalid mobile number. Digits only.\n");
    }
}

void getPassengerDetails(int numPassengers, FILE *file) {
    for (int i = 0; i < numPassengers; i++) {
        char name[100], mobile[20];
        printf("\nPassenger %d:\n", i + 1);
        printf("  Name: ");
        getchar();
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;
        int age = getValidAge();
        getValidMobile(mobile);
        fprintf(file, "Passenger %d: %s, Age: %d, Mobile: %s\n", i + 1, name, age, mobile);
    }
}

int getChoice(const char *prompt, int min, int max) {
    int choice;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &choice) == 1 && choice >= min && choice <= max) break;
        printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
        while (getchar() != '\n'); 
    }
    return choice;
}

void viewBookings() {
    FILE *file = fopen("bookings.txt", "r");
    if (!file) {
        printf("\nNo bookings found.\n");
        return;
    }

    char line[256];
    printf("\n--- Bookings Present ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void cancelSpecificBooking();

void cancelBookings() {
    while (1) {
        int option = getChoice("\nCancel Options:\n  1. Cancel specific booking\n  2. Cancel all bookings\n  3. Go back\nChoose an option: ", 1, 3);
        if (option == 1) cancelSpecificBooking();
        else if (option == 2) {
            FILE *file = fopen("bookings.txt", "w");
            if (file) {
                fclose(file);
                printf("\nAll bookings have been cancelled.\n");
            } else {
                printf("\nFailed to cancel bookings.\n");
            }
        } else if (option == 3) {
            break;
        }
    }
}

void cancelSpecificBooking() {
    FILE *file = fopen("bookings.txt", "r");
    if (!file) {
        printf("\nNo bookings to cancel.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("\nUnable to open temporary file.\n");
        fclose(file);
        return;
    }

    char line[256];
    int bookingNumber = 0, selectedBooking;
    long positions[100];
    int count = 0;

    printf("\n--- Bookings ---\n");
    long pos;
    while ((pos = ftell(file)), fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Booking:", 8) == 0 || strncmp(line, "Hotel Booking:", 14) == 0 || strncmp(line, "Activity Booking:", 17) == 0) {
            bookingNumber++;
            positions[bookingNumber-1] = pos;
            printf("%d. %s", bookingNumber, line);
        }
    }

    if (bookingNumber == 0) {
        printf("No bookings to cancel.\n");
        fclose(file);
        fclose(tempFile);
        remove("temp.txt");
        return;
    }

    selectedBooking = getChoice("\nEnter the number of the booking you want to cancel: ", 1, bookingNumber);

    rewind(file);
    bookingNumber = 0;
    int skip = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Booking:", 8) == 0 || strncmp(line, "Hotel Booking:", 14) == 0 || strncmp(line, "Activity Booking:", 17) == 0) {
            bookingNumber++;
            skip = (bookingNumber == selectedBooking);
        }
        if (!skip) fputs(line, tempFile);
        if (skip && strcmp(line, "---\n") == 0) skip = 0;
    }

    fclose(file);
    fclose(tempFile);
    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");

    printf("\nSelected booking cancelled.\n");
}

int main() {
    int mainOption;
    printf("Welcome to the Travel Booking System\n");
    while (1) {
        mainOption = getChoice("\nMenu:\n  1. Book a trip\n  2. View bookings\n  3. Cancel bookings\n  4. Exit\nChoose an option: ", 1, 4);

        if (mainOption == 4) break;

        if (mainOption == 2) {
            viewBookings();
            continue;
        } else if (mainOption == 3) {
            cancelBookings();
            continue;
        }
        int i;
        printf("\nSelect a city you wish to travel:\n");
        for (i = 0; i < NUM_CITIES; i++) printf("  %2d. %s\n", i+1, cities[i]);
        int cityChoice = getChoice("Enter your choice (1-15): ", 1, NUM_CITIES);

        printf("\nYou chose %s\n", cities[cityChoice-1]);
        int option = getChoice("How would you like to plan your trip?\n  1. Pre-planned trips    2. Customize your own plan\nEnter 1 or 2: ", 1, 2);

        FILE *file = fopen("bookings.txt", "a");
        if (!file) {
            printf("Error opening bookings file.\n");
            return 1;
        }

        if (option == 1) {
            while (1) {
                printf("\nPre-planned trips for %s:\n", cities[cityChoice-1]);
                for (i = 0; i < NUM_TRIPS; i++) printf("  %d. %s\n", i+1, trips[cityChoice-1][i]);
                int tripChoice = getChoice("Select a trip (1-5): ", 1, NUM_TRIPS);

                printf("\nYou selected: \"%s\"\nTrip Details: %s\n", trips[cityChoice-1][tripChoice-1], tripDetails[cityChoice-1][tripChoice-1]);

                int proceed = getChoice("\nWould you like to:\n  1. Proceed with booking\n  2. Go back to trip list\nEnter 1 or 2: ", 1, 2);
                if (proceed == 2) continue;

                char startDate[20];
                getValidDate("Enter your desired start date (YYYY-MM-DD): ", startDate);

                int numPassengers;
                printf("Enter number of passengers: ");
                scanf("%d", &numPassengers);

                fprintf(file, "Booking: %s - %s, Start Date: %s\n", cities[cityChoice-1], trips[cityChoice-1][tripChoice-1], startDate);
                getPassengerDetails(numPassengers, file);
                fprintf(file, "---\n");

                printf("\nBooking confirmed for \"%s\" in %s starting on %s!\n", trips[cityChoice-1][tripChoice-1], cities[cityChoice-1], startDate);
                break;
            }
        } else {
            int customType = getChoice("\nCustomize your plan:\n  1. Choose a hotel    2. Choose an activity\nEnter 1 or 2: ", 1, 2);
            int choice;
            char startDate[20], endDate[20];

            if (customType == 1) {
                printf("\nPick a hotel in %s:\n", cities[cityChoice-1]);
                for (i = 0; i < NUM_HOTELS; i++) printf("  %d. %s\n", i+1, hotels[cityChoice-1][i]);
                choice = getChoice("Select a hotel (1-5): ", 1, NUM_HOTELS);

                getValidDate("Enter your booking start date (YYYY-MM-DD): ", startDate);
                while (1) {
                    getValidDate("Enter your booking end date (YYYY-MM-DD): ", endDate);
                    if (!compareDates(startDate, endDate)) {
                        printf("End date must be after start date.\n");
                    } else break;
                }
            } else {
                printf("\nPick an activity in %s:\n", cities[cityChoice-1]);
                for (i = 0; i < NUM_ACTIVITIES; i++) printf("  %d. %s\n", i+1, activities[cityChoice-1][i]);
                choice = getChoice("Select an activity (1-5): ", 1, NUM_ACTIVITIES);
                getValidDate("Enter your booking date (YYYY-MM-DD): ", startDate);
            }

            int numPassengers;
            printf("Enter number of passengers: ");
            scanf("%d", &numPassengers);

            const char *item = (customType == 1) ? hotels[cityChoice-1][choice-1] : activities[cityChoice-1][choice-1];
            if (customType == 1) {
                fprintf(file, "Hotel Booking: %s, %s, From: %s To: %s\n", item, cities[cityChoice-1], startDate, endDate);
            } else {
                fprintf(file, "Activity Booking: %s, %s, Date: %s\n", item, cities[cityChoice-1], startDate);
            }
            getPassengerDetails(numPassengers, file);
            fprintf(file, "---\n");

            if (customType == 1) {
                printf("\nHotel '%s' in %s is booked from %s to %s!\n", item, cities[cityChoice-1], startDate, endDate);
            } else {
                printf("\nActivity '%s' in %s is booked for %s!\n", item, cities[cityChoice-1], startDate);
            }
        }
        fclose(file);
        printf("\nThank you for booking, Safe travel\n");
    }
    return 0;
}