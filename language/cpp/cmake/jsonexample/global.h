//
// Created by 黄朝顺 on 2020-07-09.
//

#ifndef UNTITLED3_GLOBAL_H
#define UNTITLED3_GLOBAL_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

static std::string label_profile_name = "label_profile";

class DynamicDict {
 public:
  std::string file_name;
  DynamicDict(std::string file_name_p) {
    file_name = file_name_p;
  }
  virtual bool load() = 0;
  std::string fullFileName(std::string file_name_t) {
    return file_name_t+".txt";
  }

  virtual ~DynamicDict() = default;
};

struct LabelItem {
  std::string label;
  double playpv;
  double playuvs_play_pvlabel;

  void to_string() const {
    std::cout << "label: " << label << " playpv: " << playpv <<
      " playuvs_play_pvlabel: " << playuvs_play_pvlabel << std::endl;
  }
};

class LabelProfileDict : public DynamicDict {
 public:
  LabelProfileDict(const std::string& filename): DynamicDict(filename) {};
  bool load() override;

  std::unordered_map<std::string, std::pair<double, double>>&
  getLevelMapping() {
    return level_mapping_;
  }

  std::vector<LabelItem>& getLabels() {
    return labels_;
  }

 private:
  bool parseLevelMapping(const nlohmann::json& j);
  bool parseLabels(const nlohmann::json& j);

  //key: level, such as "L1"; value: first: min, second: max
  std::unordered_map<std::string, std::pair<double, double>> level_mapping_;
  std::vector<LabelItem> labels_;
};

#endif //UNTITLED3_GLOBAL_H
