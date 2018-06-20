(function($) {
  polyfill();

  const settings = Drupal.settings.uhc_grades;

  renderPersonalGrade(settings);
  renderDistributionDisclaimer(settings);
  renderChart(settings);
  renderStatusTotals(settings);
  renderGradesDisclaimer(settings);

  function getChartOptions(settings) {
    return {
      chart: {
        type: 'column',
        plotBorderWidth: 7,
        plotBorderColor: '#FFF'
      },
      colors: ['#005479'],
      title: {
        text: ''
      },
      legend: {
        itemStyle: {
          fontSize: '14px',
          fontWeight: 'normal',
          textTransform: 'uppercase'
        },
        squareSymbol: false,
        symbolWidth: 0,
        symbolPadding: 0
      },
      xAxis: {
        categories: getCategories(settings),
        labels: {
          style: {
            fontSize: '13px'
          }
        },
        lineColor: '#979797',
        tickWidth: 0
      },
      yAxis: {
        gridLineWidth: 0,
        labels: {
          enabled: false,
        },
        lineColor: '#979797',
        lineWidth: 1,
        title: {
          text: null
        }
      },
      series: [{
        name: settings.text.legend,
        data: getDistribution(settings)
      }],
      plotOptions: {
        column: {
          dataLabels: {
            enabled: true,
            style: {
              fontSize: '13px'
            },
            formatter: function () {
              return this.y + ' ' + settings.text.pieces;
            },
          },
          groupPadding: 0.02,
          pointPadding: 0
        }
      },
      tooltip: {
        enabled: false,
      },
      credits: {
        enabled: false
      }
    };
  }

  function getCategories(settings) {
    const categories = settings.grades.grade_distribution.map(function (grade) {
      return grade.grade.filter(function (grade) {
        return grade.langcode == settings.language
      })[0].text
    });

    return isNumericDistribution(settings.grades) ? ['1', '2', '3', '4', '5'] : categories;
  }

  function getDistribution(settings) {
    const distribution = getCategories(settings).map(function (value) {
      const found = settings.grades.grade_distribution.find(function (grade) {
        return grade.grade.find(function (grade) {
          return grade.text == value;
        });
      });

      return found ? found.total : 0;
    });

    return isNumericDistribution(settings.grades) ? distribution.filter(isInteger) : distribution;
  }

  function isNumericDistribution(grades) {
    return getNumericGrades(grades).length > 0;
  }

  function getNumericGrades(grades) {
    return grades.grade_distribution.filter(function (grade) {
      return isNumericGrade(grade);
    });
  }

  function isNumericGrade(grade) {
    return grade.grade !== undefined && isInteger(grade.grade[0].text)
      || grade.text !== undefined && isInteger(grade.text);
  }

  function isInteger(value) {
    return Number.isInteger(Number.parseInt(value));
  }

  function renderPersonalGrade(settings) {
    if (settings.grades) {
      const html = '<div id="personal-grade">'
        + '<label class="personal-grade-label accordion-content-item--label">' + settings.text.personalGrade + '</label>'
        + '<p class="personal-grade-grade">' + getPersonalGrade(settings) + '</p>'
        + '</div>';

      $('#grades-chart').before(html);
    }
  }

  function getPersonalGrade(settings) {
    return settings.grades.personalGrade.grade.filter(function (grade) {
      return grade.langcode == settings.language;
    })[0].text;
  }

  function renderDistributionDisclaimer(settings) {
    if (settings.grades && !hasGradeDistribution(settings.grades)) {
      const distributionDisclaimer = settings.text.distributionDisclaimer;
      const html = '<div id=distribution-disclaimer><p>' + distributionDisclaimer + '</p></div>';
      $('#grades-chart').before(html);
    }
  }

  function renderChart(settings) {
    if (hasGradeDistribution(settings.grades)) {
      $('#grades-chart').wrap('<div id="chart-container"></div>');
      $('#chart-container').prepend('<label class="accordion-content-item--label">' + settings.text.gradeDistribution + '</label>');
      Highcharts.chart('grades-chart', getChartOptions(settings));
    }
  }

  function hasGradeDistribution(grades) {
    return grades !== null && grades.grade_distribution !== undefined;
  }

  function renderStatusTotals(settings) {
    if (hasGradeDistribution(settings.grades)) {
      const statusGradeRows = getStatusGrades(settings.grades).map(function (grade) {
        const label = grade.grade.filter(function (grade) {
          return grade.langcode == settings.language
        })[0].text;

        return '<div class="status-total-row">'
          + '<span class="status-label">' + label + ': </span>'
          + '<span class="status-total">' + grade.total + ' ' + settings.text.pieces + '</span>'
          + '</div>';
      }).join('');

      const html = '<div id="status-totals">' + statusGradeRows + '</div>';

      $('#chart-container').after(html);
    }
  }

  function getStatusGrades(grades) {
    return grades.grade_distribution.filter(function (grade) {
      return !isNumericGrade(grade);
    });
  }

  function renderGradesDisclaimer(settings) {
    if (hasGradeDistribution(settings.grades)) {
      const gradesDisclaimer = settings.text.gradesDisclaimer;
      const html = '<div id=grades-disclaimer><p>' + gradesDisclaimer + '</p></div>';
      $('#status-totals').after(html);
    }
  }

  function polyfill() {
    // https://tc39.github.io/ecma262/#sec-array.prototype.find
    if (!Array.prototype.find) {
      Object.defineProperty(Array.prototype, 'find', {
        value: function(predicate) {
         // 1. Let O be ? ToObject(this value).
          if (this == null) {
            throw new TypeError('"this" is null or not defined');
          }

          var o = Object(this);

          // 2. Let len be ? ToLength(? Get(O, "length")).
          var len = o.length >>> 0;

          // 3. If IsCallable(predicate) is false, throw a TypeError exception.
          if (typeof predicate !== 'function') {
            throw new TypeError('predicate must be a function');
          }

          // 4. If thisArg was supplied, let T be thisArg; else let T be undefined.
          var thisArg = arguments[1];

          // 5. Let k be 0.
          var k = 0;

          // 6. Repeat, while k < len
          while (k < len) {
            // a. Let Pk be ! ToString(k).
            // b. Let kValue be ? Get(O, Pk).
            // c. Let testResult be ToBoolean(? Call(predicate, T, « kValue, k, O »)).
            // d. If testResult is true, return kValue.
            var kValue = o[k];
            if (predicate.call(thisArg, kValue, k, o)) {
              return kValue;
            }
            // e. Increase k by 1.
            k++;
          }

          // 7. Return undefined.
          return undefined;
        }
      });
    }

    // Number.parseInt
    if (Number.parseInt === undefined) {
      Number.parseInt = window.parseInt;
    }

    // Number.isInteger
    Number.isInteger = Number.isInteger || function(value) {
      return typeof value === 'number' &&
        isFinite(value) &&
        Math.floor(value) === value;
    };
  }

})(jQuery);